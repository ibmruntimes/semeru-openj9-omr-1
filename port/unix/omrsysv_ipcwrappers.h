/*******************************************************************************
 * Copyright IBM Corp. and others 2020
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] https://openjdk.org/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/
#ifndef omr_sysv_wrappers_h
#define omr_sysv_wrappers_h

#include <stddef.h>
#include "omrportptb.h"
#include "omrportpriv.h"
#include "omrport.h"
#include "portnls.h"
#include "ut_omrport.h"
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#if defined (J9ZOS390)
#include <sys/__getipc.h>
#endif


typedef union {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
} semctlUnion;

/*ftok*/
int omr_ftokWrapper(OMRPortLibrary *portLibrary, const char *baseFile, int proj_id);

/*semaphores*/
int omr_semgetWrapper(OMRPortLibrary *portLibrary, key_t key, int nsems, int semflg);
int omr_semctlWrapper(OMRPortLibrary *portLibrary, BOOLEAN storeError, int semid, int semnum, int cmd, ...);
int omr_semopWrapper(OMRPortLibrary *portLibrary, int semid, struct sembuf *sops, size_t nsops);

/*memory*/
int omr_shmgetWrapper(OMRPortLibrary *portLibrary, key_t key, size_t size, int shmflg);
int omr_shmctlWrapper(OMRPortLibrary *portLibrary, BOOLEAN storeError, int shmid, int cmd, struct shmid_ds *buf);
void * omr_shmatWrapper(OMRPortLibrary *portLibrary, int shmid, const void *shmaddr, int shmflg);
int omr_shmdtWrapper(OMRPortLibrary *portLibrary, const void *shmaddr);

/*z/OS sysv helper function*/
#if defined (J9ZOS390)
int omr_getipcWrapper(OMRPortLibrary *portLibrary, int id, IPCQPROC *info, size_t length, int cmd);
#endif

#endif

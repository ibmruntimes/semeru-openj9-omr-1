/*******************************************************************************
 * Copyright IBM Corp. and others 2001
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
/*
 * ===========================================================================
 * Module Information:
 *
 * DESCRIPTION:
 * Replace the system header file "locale.h" so that we can redefine
 * the i/o functions that take/produce character strings
 * with our own ATOE functions.
 *
 * The compiler will find this header file in preference to the system one.
 * ===========================================================================
 */

#if __TARGET_LIB__ == 0X22080000                                   /*ibm@28725*/
#include <//'PP.ADLE370.OS39028.SCEEH.H(locale)'>                  /*ibm@28725*/
#else                                                              /*ibm@28725*/
#include "prefixpath.h"
#include PREFIXPATH(locale.h)                                   /*ibm@28725*/
#endif                                                             /*ibm@28725*/

#if defined(IBM_ATOE)

	#if !defined(IBM_ATOE_LOCALE)
		#define IBM_ATOE_LOCALE

		#ifdef __cplusplus
            extern "C" {
		#endif

        char * atoe_setlocale(int , const char *);

		#ifdef __cplusplus
            }
		#endif

		#undef setlocale

		#define setlocale	atoe_setlocale

	#endif

#endif

/* END OF FILE */


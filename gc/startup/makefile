###############################################################################
# Copyright IBM Corp. and others 2015
# 
# This program and the accompanying materials are made available under
# the terms of the Eclipse Public License 2.0 which accompanies this
# distribution and is available at https://www.eclipse.org/legal/epl-2.0/
# or the Apache License, Version 2.0 which accompanies this distribution and
# is available at https://www.apache.org/licenses/LICENSE-2.0.
#      
# This Source Code may also be made available under the following
# Secondary Licenses when the conditions for such availability set
# forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
# General Public License, version 2 with the GNU Classpath
# Exception [1] and GNU General Public License, version 2 with the
# OpenJDK Assembly Exception [2].
#    
# [1] https://www.gnu.org/software/classpath/license.html
# [2] https://openjdk.org/legal/assembly-exception.html
# 
# SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
###############################################################################

top_srcdir := ../..
include $(top_srcdir)/omrmakefiles/configure.mk

MODULE_NAME := omrgcstartup
ARTIFACT_TYPE := archive

OBJECTS := $(patsubst %.cpp,%$(OBJEXT),$(wildcard *.cpp))
OBJECTS += $(patsubst %.c,%$(OBJEXT),$(wildcard *.c))

MODULE_INCLUDES += ../base ../base/standard ../include ../stats ../structs ../verbose $(top_srcdir)/omr/startup $(OMRGLUE_INCLUDES)

ifeq (linux,$(OMR_HOST_OS))
  ifeq (x86,$(OMR_HOST_ARCH))
    MODULE_CFLAGS += -funroll-loops
    MODULE_CXXFLAGS += -funroll-loops
  endif
endif

#<!-- mminit and mmparse include a number of static functions which aren't all used in some specifications. Suppress warnings about these. --> 
#<flag name="/w34189" asmflag="false" definition="false">
#<include-if condition="spec.win_x86[^-]*"/>
#</flag>
#<flag name="-Wno-unused-function" asmflag="false" definition="false">
#<include-if condition="spec.linux_x86.*"/>
#</flag>
include $(top_srcdir)/omrmakefiles/rules.mk


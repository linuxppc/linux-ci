#
# Copyright 2020 Advanced Micro Devices, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.
#
# Authors: AMD
#
#

ifdef CONFIG_DRM_AMD_DC_FP
###############################################################################
# DCN20
###############################################################################
MMHUBBUB_DCN20 = dcn20_mmhubbub.o

AMD_DAL_MMHUBBUB_DCN20 = $(addprefix $(AMDDALPATH)/dc/mmhubbub/dcn20/,$(MMHUBBUB_DCN20))

AMD_DISPLAY_FILES += $(AMD_DAL_MMHUBBUB_DCN20)

###############################################################################
# DCN32
###############################################################################
MMHUBBUB_DCN32 = dcn32_mmhubbub.o

AMD_DAL_MMHUBBUB_DCN32 = $(addprefix $(AMDDALPATH)/dc/mmhubbub/dcn32/,$(MMHUBBUB_DCN32))

AMD_DISPLAY_FILES += $(AMD_DAL_MMHUBBUB_DCN32)

###############################################################################
# DCN35
###############################################################################
MMHUBBUB_DCN35 = dcn35_mmhubbub.o

AMD_DAL_MMHUBBUB_DCN35 = $(addprefix $(AMDDALPATH)/dc/mmhubbub/dcn35/,$(MMHUBBUB_DCN35))

AMD_DISPLAY_FILES += $(AMD_DAL_MMHUBBUB_DCN35)
endif


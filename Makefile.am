AUTOMAKE_OPTIONS     = 1.4 foreign

MAINTAINERCLEANFILES = Makefile.in aclocal.m4 config.guess \
                       config.h.in config.sub configure install-sh \
		       ltconfig ltmain.sh missing mkinstalldirs \
		       stamp-h.in acconfig.h depcomp config.h.in~ test.edj

bin_PROGRAMS = test_elegance

test_elegance_LDADD = @ELEMENTARY_LIBS@

INCLUDES = \
@ELEMENTARY_CFLAGS@

test_elegance_SOURCES = \
test.c \
test.h

test_elegancedir = $(libdir)

filesdir = $(datadir)
files_DATA = test.edj

EDJE_CC = @edje_cc@
EDJE_FLAGS = -v -id . -fd .
EXTRA_DIST = \
test.edc
test.edj: Makefile $(EXTRA_DIST)
	$(EDJE_CC) $(EDJE_FLAGS) \
	test.edc test.edj

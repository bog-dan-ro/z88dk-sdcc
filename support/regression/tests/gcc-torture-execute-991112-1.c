/*
   991112-1.c from the execute part of the gcc torture tests.
 */

#include <testfwk.h>

#ifdef __SDCC
#pragma std_c99
#pragma disable_warning 85
#endif

#include <ctype.h>

/* This code was miscompiled at -O3 on x86.
   Reported by Jim Meyering; distilled from bash.  */

int rl_show_char (int c) { return 0; }

int rl_character_len (int c, int pos)
{
  return isprint (c) ? 1 : 2;
}

void
testTortureExecute (void)
{
#if !defined (__SDCC_hc08) && !defined (__SDCC_s08) && !defined (__SDCC_ds390) && !defined (__SDCC_mcs51)
#if !((defined __SDCC_stm8) && defined (__SDCC_MODEL_LARGE)) // Assembler not suitable for 24-bit function pointers
  int (*x)(int, int) = rl_character_len;
  if (x('a', 1) != 1)
    ASSERT (0);
  if (x('\002', 1) != 2)
    ASSERT (0);
  return;
#endif
#endif
}


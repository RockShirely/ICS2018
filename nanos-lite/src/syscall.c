#include "common.h"
#include "syscall.h"
#include "proc.h"
#include "fs.h"


_Context* do_syscall(_Context *c) {
  uintptr_t a[4];
  uintptr_t result = -1;
  a[0] = c->GPR1;
  a[1] = c->GPR2;
	a[2] = c->GPR3;
	a[3] = c->GPR4;
  Log("%d", a[1]);
  switch (a[0]) {
    case SYS_yield:
			result = 1;
			break;
		case SYS_exit:
      _halt(a[0]);
      break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }

  c->GPRx = result;
  return NULL;
}

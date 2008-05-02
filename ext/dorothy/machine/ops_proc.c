
#include "machine.h"

/*
 * z_call_n, call a subroutine and discard its result.
 *
 *      zargs[0] = packed address of subroutine
 *      zargs[1] = first argument (optional)
 *      ...
 *      zargs[7] = seventh argument (optional)
 *
 */

void z_call_n( zmachine *zm ) {
  if( zm->zargs[0] != 0 ) {
    p_call( zm, zm->zargs[0], zm->zargc - 1, zm->zargs + 1, 1 );
  }
}

/*
 * z_call_s, call a subroutine and store its result.
 *
 *      zargs[0] = packed address of subroutine
 *      zargs[1] = first argument (optional)
 *      ...
 *      zargs[7] = seventh argument (optional)
 *
 */

void z_call_s( zmachine *zm ) {   
  if( zm->zargs[0] != 0 ) {
    p_call( zm, zm->zargs[0], zm->zargc - 1, zm->zargs + 1, 0 );
  }
  else {
    p_store( zm, 0 );
  }
}

/*
 * z_load, store the value of a variable.
 *
 *      zargs[0] = variable to store
 *
 */

void z_load( zmachine *zm ) {
  zword variable = zm->zargs[0];
  zword value;

  if( variable == 0 ) {
    value = *zm->sp;
  }
  else if( variable < 16 ) {
    value = *(zm->fp - variable);
  }
  else {
    value = p_load_global( zm, variable );
  }

  p_store( zm, value );
}

/*
 * z_store, write a value to a variable.
 *
 *      zargs[0] = variable to be written to
 *      zargs[1] = value to write
 *
 */

void z_store( zmachine *zm ) {
  zword variable = zm->zargs[0];
  zword value = zm->zargs[1];

  if( variable == 0 )
    *zm->sp = value;
  else if( variable < 16 ) {
    *(zm->fp - variable) = value;
  }
  else {
    p_store_global( zm, variable, value );
  }
}

void z_ret( zmachine *zm ) {

}

void z_ret_popped( zmachine *zm ) {

}

void z_rfalse( zmachine *zm ) {

}

void z_rtrue( zmachine *zm ) {

}


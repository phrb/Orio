void PackAligned(double* src, double* dest, const int stride, const int nelms, const int cnt) {

  // __builtin_prefetch (&src[isrc]  , 1, 0);
  // __builtin_prefetch (&dest[idest], 0, 0);
  /*@ begin PerfTuning (
        def performance_params {
          param PTRS[] = [('src')];
          param DIST[] = range(7,257,8);
          param CFLAGS[] = map(join, product(['-fprefetch-loop-arrays']));
        }
        def input_params {
          param nelms[]  = range(100,101);
          param cnt[]    = range(150,151);
          param stride[] = range(200,201);
        }
        def input_vars {
          decl dynamic double  src[nelms*cnt*stride] = random;
          decl dynamic double dest[nelms*cnt] = 0;
        }
        def build {
          arg build_command = 'gcc @CFLAGS';
        }
        def performance_counter {
          arg method = 'basic timer';
          arg repetitions = 5;
        }
  ) @*/

  register int i, j, isrc=0, idest=0;
  double *init_src=src;

  /*@ begin Loops(transform Pack(prefetch=PTRS, prefetch_distance=DIST)

  for(i=cnt; i; i--) {
    for(j=nelms; j; j--) {
      dest[idest++] = src[isrc++];
    }
    src += stride;
    isrc = 0;
  }

  ) @*/


  /*@ end @*/

  src=init_src;

  /*@ end @*/
}

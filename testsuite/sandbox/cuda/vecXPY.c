void VecXPY(int n, double *x, double *y) {

    register int i;

    /*@ begin PerfTuning (
          def performance_params {
            param TC[] = range(16,513,16);
            param CB[] = [True, False];
            param PHM[] = [False];
            param SC[] = range(1,3);
          }
          def build {
            arg build_command = 'nvcc -arch=sm_20';
          }
          def input_params {
            param N[] = [1000];
          }
          def input_vars {
            decl static double y[N] = 0;
            decl static double x[N] = random;
          }
          def performance_counter {
            arg method = 'basic timer';
            arg repetitions = 10;
          }
    ) @*/

    int n=N;

    /*@ begin Loop (
          transform CUDA(threadCount=TC, cacheBlocks=CB, pinHostMem=PHM, streamCount=SC)
        for (i=0; i<=n-1; i++)
          y[i]=x[i]+y[i];
    ) @*/

    for (i=0; i<=n-1; i++)
        y[i]=x[i]+y[i];

    /*@ end @*/
    /*@ end @*/
}

/*@ begin PerfTuning (        
  def build
  {
  arg build_command = 'gcc -O3 -fopenmp '; 
  arg libs = '-lm -lrt';
  }
   
  def performance_counter         
  {
    arg repetitions = 35;
  }
  
  let VR = 500;
  let OR = 40;

  def performance_params
  {
 
    param T1_I[] = [1,16,32,64,128,256,512];
    param T1_J[] = [1,16,32,64,128,256,512];
    param T1_K[] = [1,16,32,64,128,256,512];
    param T1_L[] = [1,16,32,64,128,256,512];
    param T1_M[] = [1,16,32,64,128,256,512];

    param T1_Ia[] = [1,64,128,256,512,1024,2048];
    param T1_Ja[] = [1,64,128,256,512,1024,2048];
    param T1_Ka[] = [1,64,128,256,512,1024,2048];
    param T1_La[] = [1,64,128,256,512,1024,2048];
    param T1_Ma[] = [1,64,128,256,512,1024,2048];

    param U1_I[] = range(1,31);
    param U1_J[] = range(1,31);
    param U1_K[] = range(1,31);
    param U1_L[] = range(1,31);
    param U1_M[] = range(1,31);


  }

  def search
  {
    arg algorithm = 'Randomsearch';
    arg total_runs = 10000;
  }

  def input_params
  {
    param VSIZE = 500;
    param OSIZE = 20;
    param V = 500;
    param O = 20;
    
    }

  def input_vars
  {
   
    decl dynamic double A2[V][O] = random;
    decl dynamic double T[V][O][O][O] = random;
    decl dynamic double R[V][V][O][O] = 0;
  }
) @*/

#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

int i, j, k,l,m;
int ii, jj, kk,ll,mm;
int iii, jjj, kkk,lll,mmm;


/*@ begin Loop(
  transform Composite(
    tile = [('i',T1_I,'ii'),('j',T1_J,'jj'),('k',T1_K,'kk'),('l',T1_L,'ll'),('m',T1_M,'mm'),
            (('ii','i'),T1_Ia,'iii'),(('jj','j'),T1_Ja,'jjj'),(('kk','k'),T1_Ka,'kkk'), (('ll','l'),T1_La,'lll'), (('mm','m'),T1_Ma,'mmm')],
    unrolljam = (['i','j','k','l','m'],[U1_I,U1_J,U1_K,U1_L,U1_M])
)
  for(i=0; i<=V-1; i++) 
    for(j=0; j<=V-1; j++) 
      for(k=0; k<=O-1; k++) 
        for(l=0; l<=O-1; l++) 
	  for(m=0; m<=O-1; m++) 
	    R[i][j][k][l] = R[i][j][k][l] + T[i][m][k][l] * A2[j][m];

) @*/

/*@ end @*/
/*@ end @*/


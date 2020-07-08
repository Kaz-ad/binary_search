#include <stdio.h>
#include <math.h>

int n;
int k;
int A[100000];

/* 最大仕事量がx以下となるようにk人に仕事を割り当てられるかを判定 */
int p(int x){
  int i, worker, works;
  works = 0;
  worker = 1;
  for (i = 0; i < n; i++){
    if(x < A[i]){
      return 0;
    }
    if(x >= works + A[i]){
      works += A[i];
    }
/* xを超過したら次の人に渡す */
    else{
      worker++;
      works = A[i];
    }
    }
  return worker <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ub = pow(10, 9.0);
  lb = 0;
  while(ub -lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("% d \n", ub);



  return 0;
}

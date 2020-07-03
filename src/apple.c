#include <stdio.h>
#include <math.h>

int n;
int k;
int A[100000];

int p(int x){
  int i, j;
  j = 0;
  for (i = 0; i < n; i++)
  {
    j += (A[i] + x - 1) / x;
  }
  return j <= k;
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

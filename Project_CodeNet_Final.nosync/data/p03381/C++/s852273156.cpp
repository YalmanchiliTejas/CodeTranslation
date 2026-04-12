#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
   int N, A[200000], B[200000];
   scanf("%d", &N);
   for(int i = 0; i < N; i++){ scanf("%d", &A[i]); B[i] = A[i]; }
   sort(B, B + N);
   for(int i = 0; i < N; i++){
      if(A[i] <= B[N/2-1]) printf("%d\n",B[N/2]);
      else printf("%d\n",B[N/2-1]);
   }
}
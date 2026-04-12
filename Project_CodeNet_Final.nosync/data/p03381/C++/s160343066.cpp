#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>


using namespace std;


int a[200000], b[200000];
int n;
int c, cc;

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++){
    b[i] = a[i];
  }
  sort(a, a+n);

  c = a[(n - 1)/2];
  cc = a[(n - 1)/2 + 1];

  for(int i = 0; i < n; i++){
    if(b[i] <= c){
      printf("%d\n", cc);
    }else{
      printf("%d\n", c);
    }
  }
  return 0;
}
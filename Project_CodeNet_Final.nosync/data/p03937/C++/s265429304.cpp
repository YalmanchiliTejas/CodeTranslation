#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int nmax = 1000005; const LL inf = 2e18;

char a[10][10];
int N,M,st[10][10],nr,ok;

inline bool Valid(int i,int j){
 if(i < 1 || i > N || j > M || j < 1)return false;
 return true;
}

void Back(int i,int j,int cnt){
   if(!Valid(i,j))return;
   if(cnt == nr)ok = 1;
   if(a[i+1][j] == '#'){
   st[i+1][j] = true;
   Back(i+1,j,cnt+1);
   st[i+1][j] = false;
   }
   if(a[i][j+1] == '#'){
   st[i][j+1] = true;
   Back(i,j+1,cnt+1);
   st[i][j+1] = false;
   }
}

int main(){
//   #ifndef GLOBAL_JUDGE
//      freopen("txt.in","r",stdin);
//      freopen("txt.out","w",stdout);
//   #endif // GLOBAL_JUDGE
   int i,j;
   cin >> N >> M;
   for(i = 1; i <= N; ++i)
      for(j = 1; j <= M; ++j){
         cin >> a[i][j];
         if(a[i][j] == '#')++nr;
      }
      if(a[1][1] == '.'){
         cout << "Impossible\n";
         return 0;
      }
   Back(1,1,1);
   if(ok){
      cout << "Possible\n";
      return 0;
   }
   cout << "Impossible\n";
   return 0;
}

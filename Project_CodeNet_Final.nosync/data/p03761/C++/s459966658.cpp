#include <bits/stdc++.h>

#define INF 1 << 29
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)

using namespace std;

typedef pair<int,int> pii;
typedef long long int ll;

void gen_sosuu(int sosuu[]){
  REP(i,100010){
    sosuu[i] = true;
  }
  sosuu[0] = false;
  sosuu[1] = false;
  sosuu[2] = true;
  FOR(i,2,sqrt(100000)+1){
    if(sosuu[i] == false) continue;
    for(int j = 2; i*j<=100000;j++){
      //printf("%d %d %d\n",i*j,i,j);
      sosuu[i*j] =false;
    }
  }
}

int n;
string s;
int cnt[50][26] = {{0}};
int ans[26] = {0};

int main(){
  scanf("%d",&n);
  REP(i,n){
    cin >> s;
    REP(j,s.size()){
      cnt[i][s[j]-'a']++;
    }
  }
  REP(i,26){
    ans[i] = cnt[0][i];
    FOR(j,1,n){
      ans[i] = min(ans[i],cnt[j][i]);
    }
    REP(j,ans[i]){
      printf("%c",'a'+i);
    }
  }
  printf("\n");
}

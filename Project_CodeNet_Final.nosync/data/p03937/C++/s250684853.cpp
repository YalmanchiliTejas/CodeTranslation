#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define P pair<int,int>
#define Abs(a,b) max(a,b)-min(a,b)
#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define Cout(x) cout<<(x)<<endl

typedef long long ll;

using namespace std;

const int INF = 1e9,MOD = 1e9 + 7;
const ll LINF = 1e18;

//while(x!=0){
            //sum+=x%10;
           // x/=10;
        //}
        //各桁の和

//pair<int,int> p[100000];
//P r[100000];
//cin >> tmp;
//p[i]=make_pair(tmp,i);
//cout << p[i].second+1 << endl;//ペアの右側つまりiを出力

//s.find(w[i])==string::npos
//findの使い方

//for(int i=0;i<n;i++){
   // b[i]=x%2;
    //x/=2;
  //}二進数

long long int n=1,cnt=0,ans=0,a,b,c,cmp,data,m,h,x,y,xcmp=0,ycmp=0,sum=0;

char s[10][10];

vector<int> z;

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

       cin >> a >> b;
       rep(i,a){
           rep(j,b){
               cin >> s[i][j];
               if(s[i][j]=='#'){
                   cnt++;
               }
           }
       }
     if(cnt==a+b-1){
         Cout("Possible");
     }
     else{
         Cout("Impossible");
     }
return 0;
}

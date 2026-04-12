    #include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Abs(a,b) max(a,b)-min(a,b)
#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define Cout(x) cout<<(x)<<endl
#define POSSIBLE(condition) if(condition){cout << "POSSIBLE" << endl;}else{cout << "IMPOSSIBLE" << endl;}
#define Possible(condition) if(condition){cout << "Possible" << endl;}else{cout << "Impossible" << endl;}
#define possible(condition) if(condition){cout << "possible" << endl;}else{cout << "impossible" << endl;}
#define Size(n) (n).size()

typedef long long ll;


using namespace std;

const int INF = 1e9,MOD = 1e9 + 7;
const ll LINF = 1e18;

/*---------------------------------------------------------------
long long int kaizyo(long long int hh){
    cmp=1;
    while(hh>1){
        cmp=(cmp*hh)%MOD;
        hh--;
    }
    return cmp;
}
long long int ruizyo(long long int aa, long long int bb){
    if(aa==0){
        return 1;
    }
    else if(aa%2==0){
        long long int tt=ruizyo(aa/2,bb);
        return (tt*tt)%MOD;
    }
    else{
        return (ruizyo(aa-1,bb)*bb)%MOD;
    }
}フェルマ－のア
---------------------------------------------------------------

while(x!=0){
            sum+=x%10;
          / x/=10;
        }
        各桁の和
---------------------------------------------------------------

pair<int,int> p[100000];
cin >> tmp;
p[i]=make_pair(tmp,i);
cout << p[i].second+1 << endl;//ペアの右側つまりiを出力
---------------------------------------------------------------

s.find(w[i])==string::npos
findの使い方
---------------------------------------------------------------

for(int i=0;i<n;i++){
    b[i]=x%2;
    x/=2;
  }二進数
---------------------------------------------------------------

bool f[100001];//1000000以下の素数を調べよう！
rrep(i,2,100001){
       f[i]=false;
    }
rrep(i,2,100001){
        if(!f[i]){
            for(int j=i+i;j<=100000;j+=i){
                f[j]=true;
            }
        }
    }
    for(int i=3;i<=100000;i+=2){
        if(!f[i]){
            c[i]++;
        }
    }
---------------------------------------------------------------

visited=vector<vector<bool>>(10,vector<bool>(10,false));アを全部falseに
---------------------------------------------------------------

long long gcd(long long aaa,long long bbb){
    if(bbb==0){
        return aaa;
    }
    return gcd(bbb,aaa%bbb);
}
 
long long lcm(long long aaa,long long bbb){
    long long g = gcd(aaa,bbb);
    return aaa/g * bbb;
}左から最大公約数と最小公倍数


---------------------------------------------------------------

long long int prime_cnt[10000];
       for(int i=2;i*i<=n;i++){
           while(n%i==0){
               n/=i;
               prime_cnt[i]+=1;
           }
           if(n>1){
               prime_cnt[n]+=1;
               break;
           }
      }ある数nを素因数分解しましょう

---------------------------------------------------------------
debug:
cout<<"i: "<<i<<" j: "<<j<<" cnt: "<<cnt<<"\n";

---------------------------------------------------------------*/

long long int n,cnt=0,ans=0,cmp,cmpp,m,h,w,x,y,sum=0,pos;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
char a[1000000],b[1000000],c[1000000],d[1000000];
bool fl=true;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

      cin>>n>>s;
     // a[0]='S';
      rep(i,n-1){
          if(i==0){
              a[0]='S';
              a[1]='S';
          }
          else{
          if(s[i]=='o'){
              if(a[i]=='S'){
                  if(a[i-1]=='S')a[i+1]='S';
                  else a[i+1]='W';
              }
              else{
                  if(a[i-1]=='S')a[i+1]='W';
                  else a[i+1]='S';
              }
          }
          else{
               if(a[i]=='S'){
                  if(a[i-1]=='S')a[i+1]='W';
                  else a[i+1]='S';
              }
              else{
                  if(a[i-1]=='S')a[i+1]='S';
                  else a[i+1]='W';
              }
          }
      }
      }
      if(s[0]=='o'){
          if(a[0]=='S'){
              if(a[1]==a[n-1])fl=true;
              else fl=false;
          }
          else{
              if(a[1]!=a[n-1])fl=true;
              else fl=false;
          }
      }
      else{
            if(a[0]=='S'){
               if(a[1]!=a[n-1])fl=true;
              else fl=false;
          }
          else{
              if(a[1]==a[n-1])fl=true;
              else fl=false;
          }
      }
      if(fl){
      if(s[n-1]=='o'){
          if(a[n-1]=='S'){
              if(a[0]==a[n-2])fl=true;
              else fl=false;
          }
          else{
              if(a[0]!=a[n-2])fl=true;
              else fl=false;
          }
      }
      else{
          if(a[n-1]=='S'){
              if(a[0]!=a[n-2])fl=true;
              else fl=false;
          }
          else{
              if(a[0]==a[n-2])fl=true;
              else fl=false;
          }
      }
      }
      if(fl){Cout(a);return 0;}
      
      rep(i,n-1){
          if(i==0){
              b[0]='W';
              b[1]='S';
          }
          else{
          if(s[i]=='o'){
              if(b[i]=='S'){
                  if(b[i-1]=='S')b[i+1]='S';
                  else b[i+1]='W';
              }
              else{
                  if(b[i-1]=='S')b[i+1]='W';
                  else b[i+1]='S';
              }
          }
          else{
               if(b[i]=='S'){
                  if(b[i-1]=='S')b[i+1]='W';
                  else b[i+1]='S';
              }
              else{
                  if(b[i-1]=='S')b[i+1]='S';
                  else b[i+1]='W';
              }
          }
      }
      }
      if(s[0]=='o'){
          if(b[0]=='S'){
              if(b[1]==b[n-1])fl=true;
              else fl=false;
          }
          else{
              if(b[1]!=b[n-1])fl=true;
              else fl=false;
          }
      }
      else{
            if(b[0]=='S'){
               if(b[1]!=b[n-1])fl=true;
              else fl=false;
          }
          else{
              if(b[1]==b[n-1])fl=true;
              else fl=false;
          }
      }
      if(fl){
      if(s[n-1]=='o'){
          if(b[n-1]=='S'){
              if(b[0]==b[n-2])fl=true;
              else fl=false;
          }
          else{
              if(b[0]!=b[n-2])fl=true;
              else fl=false;
          }
      }
      else{
          if(b[n-1]=='S'){
              if(b[0]!=b[n-2])fl=true;
              else fl=false;
          }
          else{
              if(b[0]==b[n-2])fl=true;
              else fl=false;
          }
      }
      }
      if(fl){Cout(b);return 0;}
      //Cout(a);
      
      rep(i,n-1){
          if(i==0){
              c[0]='S';
              c[1]='W';
          }
          else{
          if(s[i]=='o'){
              if(c[i]=='S'){
                  if(c[i-1]=='S')c[i+1]='S';
                  else c[i+1]='W';
              }
              else{
                  if(c[i-1]=='S')c[i+1]='W';
                  else c[i+1]='S';
              }
          }
          else{
               if(c[i]=='S'){
                  if(c[i-1]=='S')c[i+1]='W';
                  else c[i+1]='S';
              }
              else{
                  if(c[i-1]=='S')c[i+1]='S';
                  else c[i+1]='W';
              }
          }
      }
      }
      if(s[0]=='o'){
          if(c[0]=='S'){
              if(c[1]==c[n-1])fl=true;
              else fl=false;
          }
          else{
              if(c[1]!=c[n-1])fl=true;
              else fl=false;
          }
      }
      else{
            if(c[0]=='S'){
               if(c[1]!=c[n-1])fl=true;
              else fl=false;
          }
          else{
              if(c[1]==c[n-1])fl=true;
              else fl=false;
          }
      }
      if(fl){
      if(s[n-1]=='o'){
          if(c[n-1]=='S'){
              if(c[0]==c[n-2])fl=true;
              else fl=false;
          }
          else{
              if(c[0]!=c[n-2])fl=true;
              else fl=false;
          }
      }
      else{
          if(c[n-1]=='S'){
              if(c[0]!=c[n-2])fl=true;
              else fl=false;
          }
          else{
              if(c[0]==c[n-2])fl=true;
              else fl=false;
          }
      }
      }
      if(fl){Cout(c);return 0;}
      
      rep(i,n-1){
          if(i==0){
              d[0]='W';
              d[1]='W';
          }
          else{
          if(s[i]=='o'){
              if(d[i]=='S'){
                  if(d[i-1]=='S')d[i+1]='S';
                  else d[i+1]='W';
              }
              else{
                  if(d[i-1]=='S')d[i+1]='W';
                  else d[i+1]='S';
              }
          }
          else{
               if(d[i]=='S'){
                  if(d[i-1]=='S')d[i+1]='W';
                  else d[i+1]='S';
              }
              else{
                  if(d[i-1]=='S')d[i+1]='S';
                  else d[i+1]='W';
              }
          }
      }
      }
      if(s[0]=='o'){
          if(d[0]=='S'){
              if(d[1]==d[n-1])fl=true;
              else fl=false;
          }
          else{
              if(d[1]!=d[n-1])fl=true;
              else fl=false;
          }
      }
      else{
            if(d[0]=='S'){
               if(d[1]!=d[n-1])fl=true;
              else fl=false;
          }
          else{
              if(d[1]==d[n-1])fl=true;
              else fl=false;
          }
      }
      if(fl){
      if(s[n-1]=='o'){
          if(d[n-1]=='S'){
              if(d[0]==d[n-2])fl=true;
              else fl=false;
          }
          else{
              if(d[0]!=d[n-2])fl=true;
              else fl=false;
          }
      }
      else{
          if(d[n-1]=='S'){
              if(d[0]!=d[n-2])fl=true;
              else fl=false;
          }
          else{
              if(d[0]==d[n-2])fl=true;
              else fl=false;
          }
      }
      }
      if(fl){Cout(d);return 0;}
      Cout(-1);
       
return 0;
}

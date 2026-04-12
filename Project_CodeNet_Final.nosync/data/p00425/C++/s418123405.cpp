#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define rrev(i, m, n) for(int (i)=(n)-1; (i)>=(m); (i)--)
#define erev(i, m, n) for(int (i)=(n); (i)>=(m); (i)--)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T, class S> inline bool minup(T& m, S x){ return m>(T)x ? (m=(T)x, true) : false; }
template<class T, class S> inline bool maxup(T& m, S x){ return m<(T)x ? (m=(T)x, true) : false; }

const int    INF = 1000000000;
const ll     MOD = 1000000007LL;
const double EPS = 1E-12;

template<typename T> ostream& operator <<(ostream& r, const vector<T> t){vrep(v,t)r<<*v<<(v+1==t.end()?"":" ");return r;}
template<typename T> ostream& operator <<(ostream& r, const pair<vector<T>, int> p){int n=p.second;minup(n,p.first.size());rep(i,n-1)r<<p.first[i]<<' ';r<<p.first[n-1];return r;}
template<typename T> ostream& operator <<(ostream& r, const pair<T*, int> p){int n=p.second-1;rep(i,n)r<<p.first[i]<<' ';return r<<p.first[n];}
template<typename T, size_t S> ostream& operator <<(ostream& r, const T (&a)[S]){rep(i,S-1)r<<a[i]<<' ';return r<<a[S-1];}


int a[3];
int n;
string s;
int tmp;

int main()
{
  while((cin >> n) && n){
    rep(i, 3) a[i] = i + 1;
    int res = 1;
    rep(i, n){
      cin >> s;
      if(s == "North"){
        tmp = a[0];
        a[0] = a[1];
        a[1] = 7 - tmp;
      }
      else if(s == "East"){
        tmp = a[2];
        a[2] = a[0];
        a[0] = 7 - tmp;
      }
      else if(s == "West"){
        tmp = a[0];
        a[0] = a[2];
        a[2] = 7 - tmp;
      }
      else if(s == "South"){
        tmp = a[1];
        a[1] = a[0];
        a[0] = 7 - tmp;
      }
      else if(s == "Right"){
        tmp = a[1];
        a[1] = a[2];
        a[2] = 7 - tmp;
      }
      else if(s == "Left"){
        tmp = a[2];
        a[2] = a[1];
        a[1] = 7 - tmp;
      }
      res += a[0];
      //cout << a << endl;
   }
    cout << res << endl;
  }
  return 0;
}
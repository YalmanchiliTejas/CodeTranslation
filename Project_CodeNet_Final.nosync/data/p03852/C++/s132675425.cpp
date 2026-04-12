#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;

int h,w,x;
char s[1000][1000];
bool visited [1000][1000];
pair<int,int> start,goal;
queue<pair<int,pair<int,int>>> q;
vector<pair<int,int>> ino;

int main(){
  //string a,b,c,d;cin>>a>>b>>c>>d;
  char o;cin>>o;
  if(o=='a'||o=='i'||o=='u'||o=='e'||o=='o'){
    cout << "vowel";
  }else{
    cout << "consonant";
  }
}

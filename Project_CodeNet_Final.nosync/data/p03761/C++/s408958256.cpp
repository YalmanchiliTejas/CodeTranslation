#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <map>
#include <deque>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)(n);i++)
#define Rep(i,n) for(int i=0;i<=(int)(n-1);i++)
typedef long long ll;
typedef map<int,int> mint;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
typedef deque<char> dchar;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int inf=1e9+1000;
ll infi=1e18+100;

//x=10111;
//x<<2 = 1011100 (右シフト),x>>2 = 101 (左シフト)
//(x>>2)&1 = 101 & 001 = 1
//iビット目は、(x>>i) & 1 でわかる(x>>i)%2 でもよい


int n;
string s[55];
string ans;
string alpha="abcdefghijklmnopqrstuvwxyz";

int main(){
	cin>>n;
	Rep(i,n) cin>>s[i];
	Rep(i,26){
		Rep(j,50){
			int c=0;
			Rep(k,n){
				Rep(l,s[k].size()){
					if(alpha[i]==s[k][l]){
						s[k][l]='#';
						c++;
						break;
					}
					}
				}
			if(c==n){
				ans+=alpha[i];
			}
		}
	}
	cout<<ans<<endl;
	
	

  return 0;
  }


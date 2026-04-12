/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s;
int k;
signed main(){
	fastio;
	cin>>s>>k;
	int len=s.length();
	s='*'+s;
	if(k==3){//while(1);
	LL res=0;
	rb(i,1,s.length()){
		rb(j,i+1,len)
			rb(k,j+1,len){
				res++;
			}
	}
	res*=9*9*9;//cout<<res<<endl;
	int ALL=0;
	rb(i,2,len){
		if(s[i]=='0'){
			ALL+=len-i;
		}
		else{
			break;
		}
	}
	ALL*=9*9;
	rb(i,2,len){
		if(s[i]=='0'){
		}
		else{
			ALL+=(len-i)*9*('9'-s[i]);
			rb(j,i+1,len){
				if(s[j]=='0') ALL+=9;
				else{
					ALL+='9'-s[j];
					break;
				}
			}
			break;
		}
	}
	int tt=0;
	rb(i,1,len-1){
		rb(j,i+1,len-1){
			tt++;
		}
	} 
	tt*=9*9;
	tt*='9'-s[1];
	ALL+=tt;
	res-=ALL;
	cout<<res<<endl;return 0;}
	if(k==2){
//		cout<<len<<endl;
		int res=0;
		rb(i,1,len){
			rb(j,i+1,len){
				rb(k,1,9)
					rb(l,1,9)
						{
							int ok=1;
							rb(m,1,len){char this_;
								if(m==i){
//									cout<<"!"<<endl;
									this_=char('0'+k);
								}else
								if(m==j){
									this_=char('0'+l);
								}
								else{
									this_='0';
								}
//								cout<<this_<<endl;
								if(s[m]<this_){
									ok=0;
									break;
								}
								if(s[m]==this_) continue;
								break;
							}//cout<<endl;
//							cout<<i<<" "<<j<<" "<<char('0'+k)<<endl;
							res+=ok;
						}
			}
		}
		cout<<res;
	}
	else{
		int res=0;
		rb(i,1,len){
			rb(j,1,9){
				int ok=1;
				rb(m,1,len){char this_;
					if(m==i){
						this_=char('0'+j);
					}
					else this_='0';
					if(s[m]<this_){
									ok=0;
									break;
					}
					if(s[m]==this_) continue;
					break;
				}
				res+=ok;
			}
		}
		cout<<res;
	}
	return 0;
}

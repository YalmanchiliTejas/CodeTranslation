//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef unsigned long long int ll;

const int BS=524288;

int CNT,rc;
char inb[BS];

inline char gchar(void){
    if(CNT%BS==0){
        CNT=0;
        rc=fread(inb,1,BS,stdin);
    }
    return CNT<rc?inb[CNT++]:0;
}

inline ll _readint(ll *ptr){
    ll n=0,c=0;
    *ptr=0;
    while(1){
        char read=gchar();
        if(read>='0'&&read<='9')read-='0',n*=10,n+=read;
        else{*ptr=n;return n==0?0:!c;}
        c++;
    }
    *ptr=n;
    return 0;
}

inline ll readint(void){ll ptr;while(_readint(&ptr));return ptr;}

int s[550];
int t[550];

ll res[550][550];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; n=readint();
	for(int i=0;i<n;i++){
		s[i]=readint();
	}
	for(int i=0;i<n;i++){
		t[i]=readint();
	}
	vector<ll> u(n),v(n);
	for(int i=0;i<n;i++){
		u[i]=readint();
	}
	for(int i=0;i<n;i++){
		v[i]=readint();
	}
	for(int i=0;i<n;i++){
		if(s[i]==0){
			for(int j=0;j<n;j++){
				res[i][j]|=u[i];
				if(t[j]==1){
					if((v[j]|res[i][j])!=v[j]){
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}
	for(int j=0;j<n;j++){
		if(t[j]==0){
			for(int i=0;i<n;i++){
				res[i][j]|=v[j];
				if(s[i]==1){
					if((u[i]|res[i][j])!=u[i]){
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==0){
			ll p=res[i][0];
			for(int j=0;j<n;j++){
				p&=res[i][j];
			}
			if(p!=u[i]){
				printf("-1\n");
				return 0;
			}
		}
	}
	for(int j=0;j<n;j++){
		if(t[j]==0){
			ll p=res[0][j];
			for(int i=0;i<n;i++){
				p&=res[i][j];
			}
			if(p!=v[j]){
				printf("-1\n");
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==1){
			ll p=0;
			for(int j=0;j<n;j++){
				p|=res[i][j];
			}
			if((p|u[i])!=u[i]){
				printf("-1\n");
				return 0;
			}
			vector<int> need;
			for(int l=0;l<64;l++){
				if(((1LL<<l)&u[i])){
					need.push_back(l);
				}
			}
			while(need.size()){
				if(p&(1LL<<need.back())){
					need.pop_back();
					continue;
				}
				bool ok=0;
				for(int j=0;j<n;j++){
					if(t[j]==1&&(v[j]&(1LL<<need.back()))){
						ok=1;
						res[i][j]|=(1LL<<need.back());
						break;
					}
					else if(t[j]==0){
						int cnt=0;
						for(int ii=0;ii<n;ii++){
							if(res[ii][j]&(1LL<<need.back()))cnt++;
						}
						if(cnt<=n-2){
							ok=1;
							res[i][j]|=(1LL<<need.back());
							break;
						}
					}
				}
				if(!ok){
					printf("-1\n");
					return 0;
				}
				else{
					need.pop_back();
				}
			}
		}
	}
	for(int j=0;j<n;j++){
		if(t[j]==1){
			ll p=0;
			for(int i=0;i<n;i++){
				p|=res[i][j];
			}
			if((p|v[j])!=v[j]){
				printf("-1\n");
				return 0;
			}
			vector<int> need;
			for(int l=0;l<64;l++){
				if(((1LL<<l)&v[j])){
					need.push_back(l);
				}
			}
			while(need.size()){
				if(p&(1LL<<need.back())){
					need.pop_back();
					continue;
				}
				bool ok=0;
				for(int i=0;i<n;i++){
					if(s[i]==1&&(u[i]&(1LL<<need.back()))){
						ok=1;
						res[i][j]|=(1LL<<need.back());
						break;
					}
					else if(s[i]==0){
						int cnt=0;
						for(int jj=0;jj<n;jj++){
							if(res[i][jj]&(1LL<<need.back()))cnt++;
						}
						if(cnt<=n-2){
							ok=1;
							res[i][j]|=(1LL<<need.back());
							break;
						}
					}
				}
				if(!ok){
					printf("-1\n");
					return 0;
				}
				else{
					need.pop_back();
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

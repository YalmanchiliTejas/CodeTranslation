#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

bool _less(string &s, string &t) {
	if(s.size()<t.size())
		return true;
	return s<=t;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string N; cin>>N;
	int K; cin>>K;
	int n=N.size();
	if(K==1) {
		int ret=0;
		for (int l=1; l<=n; l++) {
			for (char ch='1'; ch<='9'; ch++) {
				string cur=string(l,'0');
				cur[0]=ch;
				if(_less(cur,N))
					ret++;
			}
		}
		cout<<ret<<"\n";
	} else if(K==2) {
		int ret=0;
		for (int l=1; l<=n; l++) {
			string cur=string(l,'0');
			for (char ch='1'; ch<='9'; ch++) {
				string cur=string(l,'0');
				for (int i=1; i<l; i++) for (char ch2='1'; ch2<='9'; ch2++) {
					cur[0]=ch; cur[i]=ch2;
					if(_less(cur,N))
						ret++;
					cur[0]='0'; cur[i]='0';
				}
			}
		}
		cout<<ret<<"\n";
	} else {
		int ret=0;
		for (int l=1; l<=n; l++) {
			string cur=string(l,'0');
			for (char ch='1'; ch<='9'; ch++) {
				for (int i=1; i<l; i++) for (char ch2='1'; ch2<='9'; ch2++) {
					for (int j=i+1; j<l; j++) for (char ch3='1'; ch3<='9'; ch3++) {
						cur[0]=ch; cur[i]=ch2; cur[j]=ch3;
						if(_less(cur,N))
							ret++;
						cur[0]='0'; cur[i]='0'; cur[j]='0';
					}
				}
			}
		}
		cout<<ret<<"\n";
	}
	return 0;
}
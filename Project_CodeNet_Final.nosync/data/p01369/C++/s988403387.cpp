#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD (ll)(1E9+7)
#define PI 3.1415926535897932384

template <class T>ostream &operator<<(std::ostream &o, const vector<T> &v)
{
	rep(i, v.size()) {
		o << (i > 0 ? " " : "") << v[i];
	}
	return o;
}



int main() {
	string right="yuiophjklnm";
	string input;
	while(1){
	    cin>>input;
	    vi v;
	    int ans=0;
	    if(input=="#") break;
	    for(int i=0;i<input.size();i++){
	        string tmp=input.substr(i,1);
	        //cout<<"*"<<right.find(tmp)<<endl;
            if(right.find(tmp)<=right.size()){
                v.push_back(1);
            }else{
                v.push_back(-1);
            }
	    }
	    //cout<<v<<endl;
	    for(int i=1;i<input.size();i++){
	        if(v[i]*v[i-1]<0){
	            ans++;
	        }
	    }
	    cout<<ans<<endl;
	}
}


#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back


vector<pair<int,string> > sort(vector<pair<int,string> > data){
	int len = data.size();
	for(int i=1;i<len;i++){
		for(int j=len-1;j>=i;j--){
			if( data[j-1].first < data[j].first ){
				swap(data[j-1],data[j]);
			}
		}
	}
	return data;
}





int main(){
    int n;
    bool f = false;
    while(cin>>n){
        if(n==0)break;
        if(f)cout<<endl;
        else f=true;
        
        vector< pair<int,string> > data;
        rep(i,n){
            string s;int w,l,d;
            cin>>s>>w>>l>>d;
            int p = w*3+d*1;
            data.pb(make_pair(p,s));
        }
		
		data = sort(data);        
        rep(i,data.size()){
            cout<<data[i].second<<","<<data[i].first<<endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
    while( 1 ){
	string s;
	cin>>s;
	if( s=="#")break;
	vector< vector<int> > t;
	vector<int> a;
	for(int i=0;i<s.size();i++){
	    if( s[i]=='b' )
	    {
		a.push_back(1);
	    }else if( s[i] == '/' ){
		t.push_back( a );
		a.clear();
	    }else{
		int j = s[i]-'0';
		for(int k = 0;k<j;k++)a.push_back(0);
	    }
	}
	t.push_back( a );
	int x,y,z,w;
	cin>>x>>y>>z>>w;
	swap( t[x-1][y-1] , t[z-1][w-1] );
	for(int i=0;i<t.size();i++){
	    int cnt = 0;
	    for(int j=0;j<t[i].size();j++){
		if( t[i][j] == 1 ){
		    if( cnt )cout<<cnt,cnt=0;
		    cout<<'b';
		}else{
		    cnt++;
		}
	    }
	    if(cnt)cout<<cnt,cnt=0;
	    if(i!=t.size()-1)cout<<'/';
	}
	cout<<endl;
    }
    return 0;
}


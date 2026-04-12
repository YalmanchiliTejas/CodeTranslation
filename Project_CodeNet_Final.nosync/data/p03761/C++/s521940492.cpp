#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
void solve(){
    int n;
    cin>>n;string str;
    map<char,int>final;
    for(int i=97;i<=122;i++){
        char c=char(i);
        final[c]=51;
    }
    for(int i=0;i<n;i++){
        map<char,int>mp;
        cin>>str;
        for(int j=0;j<str.length();j++){
            mp[str[j]]++;
        }
        //cout<<mp['b']<<'\n';
        for(int i=97;i<=122;i++){
            char c=char(i);
            final[c] = min(final[c],mp[c]);
        }
    }
    //for(auto x:final)
    //cout<<x.first<<" "<<x.second<<'\n';
    bool flag=false;
    for(auto x:final)
    {
        if(x.second!=0) {flag=true;break;}
    }
    if(!flag) {cout<<"";return;}
    for(int i=97;i<=122;i++){
        for(int j=1;j<=final[char(i)];j++)
        cout<<char(i);
    }
}
int  main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
    //cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
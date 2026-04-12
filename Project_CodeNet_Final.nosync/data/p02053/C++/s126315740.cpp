#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int h,w;
    cin>>h>>w;
    string s[h];
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    vector<pair<int,int>> v;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='B') {
                v.push_back(make_pair(i,j));
            }
        }
    }
    int ans=0;
    int n=v.size();
    vector<pair<int,int>> p;
    int x=v[0].first;
    sort(v.begin(),v.end());
    for(int i=0;i<n;){
        x=v[i].first;
        int ymin=v[i].second, ymax=v[i].second;
        i++;
        while(v[i].first==x){
            ymax=v[i].second;
            i++;
        }
        p.push_back(make_pair(x,ymin));
        p.push_back(make_pair(x,ymax));
        
    }
    int m=p.size();
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            ans = max(ans, abs(p[i].second - p[j].second) + abs(p[i].first - p[j].first));
        }
    }
    cout<<ans<<endl;
}


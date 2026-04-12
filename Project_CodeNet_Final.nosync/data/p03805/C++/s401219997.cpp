#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool check(vector<pair<int,int>>e,vector<int>p){
    if(p[0]!=1)return false;
    for(int i = 0; i < p.size()-1; i++)
    {
        pair<int,int>edge1=make_pair(p[i],p[i+1]);
        pair<int,int>edge2=make_pair(p[i+1],p[i]);
        for(int j = 0; j < e.size(); j++)
        {
            if(edge1==e[j]||edge2==e[j])break;
            if(j==e.size()-1)return false;
        }
    }
    return true;
}

int main(){
    int n,m,a,b,ans=0;  cin>>n>>m;
    vector<pair<int,int>>e;

    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        e.push_back(make_pair(a,b));
    }

    vector<int>p(n);
    iota(p.begin(),p.end(),1);

    do{if(check(e,p))ans++;}while(next_permutation(p.begin(),p.end()));
    cout<<ans<<endl;
    return 0;
}
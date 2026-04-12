#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    map<int,int>M;
    vector<pair<int,int> >V;
    int a,b;
    while(scanf("%d,%d",&a,&b),a||b){
        V.push_back(make_pair(b,a));
    }
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    int buf=100,cnt=0;
    for(int i=0;i<V.size();i++){
        if(buf>V[i].first){
            buf=V[i].first;
            cnt++;
        }
        M[buf]=cnt;
    }
    int n;
    while(cin>>n){
        int p;
        for(int j=0;j<V.size();j++){
            if(V[j].second==n){
                p=j;
                break;
            }
        }
        cout<<M[V[p].first]<<endl;
    }


}
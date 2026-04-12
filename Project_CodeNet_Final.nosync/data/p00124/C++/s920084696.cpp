#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<set>
#include<stack>

using namespace std;

int main(){
    int n,l=0;
    while(cin>>n,n){
        if(l)cout<<endl;l++;
        map<int,vector<string> >m;
        while(n--){
            string s;
            int a,b,c;
            cin>>s>>a>>b>>c;
            m[3*a+c].push_back(s);
        }
        for (map<int,vector<string> >::reverse_iterator it=m.rbegin(); it!=m.rend(); ++it){
            vector<string>v=it->second;
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<","<<it->first<<endl;
            }
        }
    }
}
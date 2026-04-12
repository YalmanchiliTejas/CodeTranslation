#include <bits/stdc++.h>

using namespace std;

vector<char> getAnd(const vector<char> v1,const vector<char> v2){
    int cnt1=0,cnt2=0;
    vector<char> res;
    while(cnt1<v1.size() && cnt2<v2.size()){
        if(v1[cnt1]==v2[cnt2]){
            res.push_back(v1[cnt1]);
            cnt1++;
            cnt2++;
        }else if(v1[cnt1]>v2[cnt2]){
            cnt2++;
        }else{
            cnt1++;
        }
    }
    res.push_back(0);
    return res;
}

int main() {
    int n,cnt;
    vector<vector<char> > vvc;
    
    string buf;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        cin >> buf;
        vector<char> vc;
        for(int j=0;j<buf.size();j++)
            vc.push_back(buf[j]);
        vvc.push_back(vc);
    }

    for(int i=0;i<n;i++){
        sort(vvc[i].begin(),vvc[i].end());
    }
        

    vector<char> res;
    if(n!=1){
        res = getAnd(vvc[0],vvc[1]);
        for(int i=2;i<n;i++){
            res = getAnd(res,vvc[i]);
        }
    }else{
        for(int i=0;i<vvc[0].size();i++)
            res.push_back(vvc[0][i]);
            res.push_back(0);
    }

    for(int i=0;i<res.size();i++){
        if(res[i]!=0)
            printf("%c",res[i]);
    }
    
    
    printf("\n");
    return 0;
}
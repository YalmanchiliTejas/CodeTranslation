#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;cin>>N;
    vector<int> cnt(26);
    string S;cin>>S;
    for(int i=0;i<S.size();i++){
        cnt[S[i]-'a']++;
    }
    for(int i=0;i<N-1;i++){
        vector<int> ncnt(26);
        cin>>S;
        for(int j=0;j<S.size();j++){
            ncnt[S[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            cnt[j]=min(cnt[j],ncnt[j]);
        }
    }
    for(int i=0;i<26;i++){
        while(cnt[i]--)cout<<(char)('a'+i);
    }
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int N;cin>>N;
    vector<int> ans(26);
    for(int i=0;i<26;i++)ans.at(i)+=50;
    string S;
    for(int i=0;i<N;i++){
        vector<int> now(26);
        cin>>S;
        for(int i=0;i<S.size();i++)now.at(S.at(i)-'a')++;
        for(int i=0;i<26;i++){
            ans.at(i)=min(ans.at(i),now.at(i));
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<ans.at(i);j++){
            cout<<char('a'+i);
        }
    }
    cout<<endl;
    return 0;
}
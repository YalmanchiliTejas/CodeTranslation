#include <bits/stdc++.h>
using namespace std;

int main(){
  
    int N;
    cin>>N;
    vector<int> A(26,100);
    for(int i=0;i<N;i++){
        string S;cin>>S;
        vector<int> B(26);
        for(int j=0;j<S.size();j++){
            B[S[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            A[j]=min(A[j],B[j]);
        }
    }
    for(int i=0;i<26;i++){
        while(A[i]>0){
            char x=i+'a';
            cout<<x;
            A[i]--;
        }
    }
    cout<<endl;
}

    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
     int N,K;
      string S;
      cin>>N>>S>>K;
      
      for(int i=0;i<S.size();i++){
        if(S.at(i)!=S.at(K-1)){S.at(i)='*';}}
      
      cout<<S<<endl;
      return 0;
    }
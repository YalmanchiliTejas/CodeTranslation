#include<bits/stdc++.h>

using namespace std;

int main(){
    long long A=0,B=0,C=0,D=0,N=0,ans=1;
    string S;



    cin>>N;
    vector<long long> vec(N);

    for(auto& x : vec)
    {
            cin>>x;
    }
    

    for(int i=1;i<N;++i){
    bool check=true;
        for(int k=0;k<i;++k){ 
            if(vec[k]>vec[i]){
                check=false;
            }
        }

        if(check){
            ans++;
        }
    }


    cout<<ans<<endl;

}
#include<iostream>
#include<vector>

using namespace std;

int main(){
    long H,W;
    cin>>H>>W;
    vector<string> vec(H);
    for(auto&x : vec)
    {
        cin>>x;
    }

    for(long i=0;i<vec.size();++i){
        if(vec[i][0]=='.'){
            bool c=true;
            for(long k=1;k<W;++k){
                if(vec[i][k]!='.'){
                    c=false;
                }                
            }
            if(c){
                vec.erase(vec.begin()+i);
                i--;
            }
        }
    }

    for(long i=0;i<vec[0].size();++i){
        if(vec[0][i]=='.'){
            bool c=true;
            for(long k=1;k<vec.size();++k){
                if(vec[k][i]!='.'){
                    c=false;
                }                
            }
            if(c){
                for(long k=0;k<vec.size();++k){
                    vec[k].erase(vec[k].begin()+i);               
                }
                i--;
            }
        }
    }

    for(auto& x : vec)
    {
        cout<<x<<endl;
    }
    
    
}
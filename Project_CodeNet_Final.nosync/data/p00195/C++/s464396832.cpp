#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int v[5];
        char name='A';
        int n=0;
        for(int i=0;i<5;i++){
            v[i]=0;
            for(int j=0;j<2;j++){
                int t;cin>>t;
                v[i]+=t;
            }
            if(v[i]==0) return 0;
            if(v[i]>n){
                n=v[i];
                name=i+'A';
            }
        }
        cout<<name<<" "<<n<<endl;
    }
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    while(true){
        vector<int> vals(5,0);
        bool valid=true;
        for(int i=0;i<5;i++){
            cin>>vals[i];
            int v=0;
            cin>>v;
            vals[i]+=v;
            if(vals[i]==0){
                valid=false;
                break;
            }
        }
        if(!valid)break;

        int max_i=0;
        for(int i=1;i<5;i++){
            if(vals[i]>vals[max_i])max_i=i;
        }

        cout<<(char)(max_i+'A')<<" "<<vals[max_i]<<endl;
    }
}

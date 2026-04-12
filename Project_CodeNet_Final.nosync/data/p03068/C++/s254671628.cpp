#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main (){
    int n,k,cnt=0;
    char w;

string data;
cin>>n;
cin>>data;
cin>>k;

w=data[k-1];

for(;n>0;n--){
    if(w==data[cnt]){
        cout<<w<<flush;
    }
    else{
            cout<<"*"<<flush;
        }
        cnt++;

}
return(0);
}
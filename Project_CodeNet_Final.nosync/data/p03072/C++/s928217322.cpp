#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int max=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>=max){
            cnt++;
            max=a;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

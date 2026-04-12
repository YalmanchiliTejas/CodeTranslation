#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#define ll long long int
#define MOD 1000000007LL
using namespace std;
int main() {
    int h,w;
    cin>>h>>w;
    int sc=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin>>c;
            if(c=='#'){
                sc++;
            }
        }
    }
    if(sc==h+w-1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
}
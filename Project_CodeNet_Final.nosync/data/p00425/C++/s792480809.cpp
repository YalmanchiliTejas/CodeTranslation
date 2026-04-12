#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define pb(a) push_back(a)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
using namespace std;

void order(int d[6], string str){
    int temp;
    if(str == "North"){
        temp = d[2];
        d[2] = d[4];
        d[4] = d[5];
        d[5] = d[0];
        d[0] = temp;
    }else if(str == "East"){
        temp = d[2];
        d[2] = d[1];
        d[1] = d[5];
        d[5] = d[3];
        d[3] = temp;
    }else if(str == "West"){
        temp = d[2];
        d[2] = d[3];
        d[3] = d[5];
        d[5] = d[1];
        d[1] = temp;
    }else if(str == "South"){
        temp = d[2];
        d[2] = d[0];
        d[0] = d[5];
        d[5] = d[4];
        d[4] = temp;
    }else if(str == "Right"){
        temp = d[0];
        d[0] = d[1];
        d[1] = d[4];
        d[4] = d[3];
        d[3] = temp;
    }else{
        temp = d[0];
        d[0] = d[3];
        d[3] = d[4];
        d[4] = d[1];
        d[1] = temp;
    }
}

int main(){
    int n;
    while(cin >> n){
       int d[6] = {5,4,1,3,2,6}, sum = 0;
       rep(i,n){
           string str;
           cin >> str;
           order(d, str);
           sum+=d[2];
       }
       if(n)
       cout << sum + 1 << endl;
    }
}
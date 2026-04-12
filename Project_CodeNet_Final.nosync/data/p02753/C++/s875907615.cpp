#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 1e5+10;
int a[N];
int main(){
    string a;
    cin >> a;
    int aa = 0 , bb = 0;
    for(auto c:a){
        if(c == 'B') bb++;
        else aa++;
    }
    if(aa &&bb ){
        cout <<"Yes\n";
    }else{
        cout <<"No\n";
    }




    return 0;
}
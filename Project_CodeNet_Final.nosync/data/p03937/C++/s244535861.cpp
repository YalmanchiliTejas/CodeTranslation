#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
using namespace std;
using P=pair<int,int>;
using PP=pair<P,P>;
using ll=long long;
int main(){
    int h,w;
    cin>>h>>w;
    int cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin>>c;
            if(c=='#')cnt++;
        }
    }
    if(cnt==h+w-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
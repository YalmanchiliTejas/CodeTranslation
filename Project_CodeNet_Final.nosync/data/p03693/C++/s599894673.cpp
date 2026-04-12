#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
int x,y,z;
cin >> x >> y >> z;
int d = (x*100)+(y*10)+(z*1);
if(d%4==0){
    cout << "YES" << endl;
}else{
    cout << "NO" << endl;
}
return 0;
}
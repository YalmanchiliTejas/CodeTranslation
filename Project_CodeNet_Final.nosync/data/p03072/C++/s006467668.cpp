#include<iostream>
#include <string.h>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    ll n,max=0,ans=0,h;
    cin >> n;
    for(int i = 0; i<n; i++){
       cin >> h;
       if(h>=max){
          ans++;
          max=h;
      }
}
cout << ans << endl;


    

    return 0;

}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int i=0;
    int ans;
    while(true){
        ans = x;
        ans=ans-y*i;
        if(i>=1){
            ans = ans-z*(i+1);
        }
        if(ans<0){
            i=i-1;
            break;
        }
        i++;
    }
    cout << i << endl;
}
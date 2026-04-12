#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>
#include <math.h>

using namespace std;
        
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int len=x,ans=0;
    while(1){
            len-=z;
            len-=y;
            if(len>=z){
                ans++;
            }else{
                cout<<ans<<endl;
                break;
            }
    }
    return 0;
}
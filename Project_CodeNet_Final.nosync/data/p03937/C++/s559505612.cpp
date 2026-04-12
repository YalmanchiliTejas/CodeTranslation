
#include <bits/stdc++.h>
using namespace std;
int h, w,ans;
string as;
int main () 
{
    cin>>h>>w;
    for (int i = 1; i <= h; ++i) {
        cin>>as;
        for (int j = 0; j <= w-1; ++j) {
            if (as[j]=='#'){
			ans++;
			
			} 
        }
    }
   	
    cout<<((ans == h + w - 1) ? "Possible" : "Impossible");
    return 0;
}
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0,cur=0;
    while(n--){
        int height;
        cin>>height;
        if(height>=cur){
            ans++;
            cur=height;
        }
    }
    cout<<ans;
    return 0;
}

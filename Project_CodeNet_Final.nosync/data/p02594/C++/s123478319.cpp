#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    # ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int x=0;
    cin>>x;
    if(x>29)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
    return 0;
}

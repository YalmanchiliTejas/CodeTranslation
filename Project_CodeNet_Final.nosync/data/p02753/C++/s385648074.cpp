#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10];
 main()
{
    string s;
    cin>>s;
    for(int i =0; i<s.size(); i++){
        a[s[i]-'A']++;
    }
    if(a[0] == 3 || a[1] == 3)cout<<"No\n";
    else cout<<"Yes\n";



    return 0;
}

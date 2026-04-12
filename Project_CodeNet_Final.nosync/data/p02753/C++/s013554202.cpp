/** Author : Parth Prajapati
 * 	Institute : Pandit Deendayal Petroleum University
**/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    if(s[0] == s[1] && s[1] == s[2])    cout<<"No";
    else    cout<<"Yes";
    return 0;
}
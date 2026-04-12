#include <iostream>
using namespace std;
int main()
{
    int n,k;
    string s[11],rep,tmp;
    cin >> n;
    cin >> tmp;
    for(int i=1;i<=n;i++)
        s[i]=tmp[i-1];
    cin >> k;
    rep=s[k];
    for(int i=1;i<=n;i++)
        if(s[i]!=rep) s[i]="*";
    for(int i=1;i<=n;i++)
        cout << s[i];
    cout << endl;
    return 0;
}
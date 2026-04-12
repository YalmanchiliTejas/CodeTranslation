#include<iostream>
using namespace std;
int main(void)
{
    string s;
    int cnt=0;
    cin >> s;
    for(int i=0;i<=1;i++)
    {
        if(s[i]!=s[i+1])
            cnt++;
    }
    if(cnt>=1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

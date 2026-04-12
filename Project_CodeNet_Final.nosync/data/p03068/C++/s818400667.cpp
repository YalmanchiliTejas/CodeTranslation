#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    char s[50];
    cin>>n;
    cin.getline(s,50);
    cin.getline(s,50);
    cin>>k;
    char kk=s[k-1];
    int lens=strlen(s);
    for(int i=0;i<lens;i++)
        s[i]=(s[i]==kk?kk:'*');
    cout<<s<<endl;
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin>>c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')cout<<"vowel\n";
    else cout<<"consonant\n";
}

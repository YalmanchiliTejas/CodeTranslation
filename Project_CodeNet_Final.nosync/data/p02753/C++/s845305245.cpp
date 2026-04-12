#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <stack>
using namespace std;
int book[151];
int main()
{
    string s;
    cin>>s;
    int j=0;

    for(int i=0;i<s.size();i++)
    {
        if(book[s[i]]==0)
        {
            book[s[i]]=1;
            j++;
        }
    }
    if(j==2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=2e5+9;
int main()
{
    FASTINOUT;
    set<char>s;
    s.insert('a');
    s.insert('u');
    s.insert('e');
    s.insert('i');
    s.insert('o');
    char z;
    cin>>z;
    if (s.find(z)!=s.end())
        cout<<"vowel\n";
    else
        cout<<"consonant";
    return 0;
}

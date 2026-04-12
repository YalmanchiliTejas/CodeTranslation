#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    bool status;
    bool a[26] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};

    while( cin >> s )
    {
        if( s == "#" )
            break;
        status = a[s[0]-'a'];
        int cnt = 0;
        for( int i = 1; i < s.size(); i++ )
            if( a[s[i]-'a'] != status )
            {
                cnt++;
                status = a[s[i]-'a'];
            }
        cout << cnt << endl;
    }
    return 0;
}

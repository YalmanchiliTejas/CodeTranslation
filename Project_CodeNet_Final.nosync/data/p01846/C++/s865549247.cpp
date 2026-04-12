#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    int y1, x1, y2, x2;

    while( cin >> s )
    {
        if( s == "#" )
            break;

        cin >> y1 >> x1 >> y2 >> x2;

        y1--; x1--; y2--; x2--;
        int h = 1, w = 0;
        for( int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '/' )
                h++;
            if( h < 2 && s[i] == 'b' )
                w++;
            else if( h < 2 )
                w += ( s[i] - '0' );
        }

        int a = 0, b = 0;
        string t[h][w];
        for( int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '/' )
            {
                a++;
                b = 0;
                continue;
            }
            if( s[i] == 'b' )
            {
                t[a][b] = 'b';
                b++;
            }
            else
                while( s[i] != '0' )
                {
                    t[a][b] = '.';
                    b++;
                    s[i]--;
                }
        }

        string temp = t[y1][x1];
        t[y1][x1] = t[y2][x2];
        t[y2][x2] = temp;

        string res = "";
        char num = '0';
        for( int i = 0; i < h; i++ )
        {
            for( int j = 0; j < w; j++ )
            {
                if( num == '0' && t[i][j] == "b" )
                    res += "b";
                else if( num != '0' && t[i][j] == "b" )
                {
                    res += num;
                    res += "b";
                    num = '0';
                }
                else
                    num++;
            }
            if( num != '0' )
            {
                res += num;
                num = '0';
            }
            res += "/";
        }
        cout << res.substr( 0, res.size() - 1 ) << endl;
    }
    return 0;
}

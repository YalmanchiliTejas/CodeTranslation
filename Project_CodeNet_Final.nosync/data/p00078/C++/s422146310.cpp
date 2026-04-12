#include<iostream>
#include<ios>
// std::left;          // 左揃えで出力
// std::right;         // 右揃えで出力
// std::internal;      // 符号左揃え、数字右揃え
// std::showpos;       // 正の符号も出力
#include<iomanip>
// std::setw(int);     // 文字幅を指定
// std::setfill(char); // 詰めたい文字を指定
using namespace std;

void makeMagicSquare( int n )
{
    int m[n][n];
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            m[i][j] = -1;

    m[n/2+1][n/2] = 1;

    int i = n / 2 + 2, j = n / 2 + 1, k = 2;
    while( true )
    {
        bool judge = true;
        for( int s = 0; s < n; s++ )
            for( int t = 0; t < n; t++ )
                if( m[s][t] == -1 )
                    judge = false;
        if( judge == true )
            break;
        if( 0 <= i && i < n && 0 <= j && j < n && m[i][j] == -1 )
        {
            m[i][j] = k;
            k++;
            i++;
            j++;
        }
        else if( i >= n && j >= n )
        {
            i = 0;
            j = 0;
        }
        else if( i >= n )
            i = 0;
        else if( j >= n )
            j = 0;
        else if( j < 0 )
            j = n - 1;
        else if( m[i][j] != -1 )
        {
            i++;
            j--;
        }
        else;
    }

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++)
            cout << setfill(' ') << right << setw(4) << m[i][j];
        cout << endl;
    }
}

int main()
{
    int n;

    while( cin >> n )
    {
        if( n == 0 )
            break;
        
        makeMagicSquare(n);
    }
    return 0;
}

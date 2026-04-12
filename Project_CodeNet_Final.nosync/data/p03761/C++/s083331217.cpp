
#include <bits/stdc++.h>
using namespace std;

int main( int argc, char *argv[] )
{
int i;
int j;
int n;
int iMax;
int iPos;
char S[60][60];
int iCnt[ 30 ];
int iMinCnt[ 30 ];
char C;
char lpOut[ 60 ];

	// 入力
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		cin >> S[i];
	}

	// 初期化
	for( i = 0; i < 26; i++ )
	{
		iCnt[i] = 0;
		iMinCnt[i] = 0;
	}

	// 個々の文字列における各文字の数をチェック
	j = 0;
	do
	{
		C = S[ 0 ][ j ];
		iCnt[ C - 'a' ]++;
		iMinCnt[ C - 'a' ]++;
		j++;
	}
	while( C != '\0' );

	// 共通する文字の数をカウント
	for( i = 1; i < n; i++ )
	{
		// 初期化
		for( j = 0; j < 26; j++ )
		{
			iCnt[j] = 0;
		}

		// 個々の文字列における各文字の数をチェック
		j = 0;
		do
		{
			 C = S[i][j];
			 iCnt[ C - 'a' ]++;
			 j++;
		}
		while( C != '\0' );

		// 最小値に更新
		for( j = 0; j < 26; j++ )
		{
			if( iMinCnt[ j ] > iCnt[ j ] )
				iMinCnt[ j ] = iCnt[ j ];
		}
	}

	// 出力
	//cout << ( A + B ) % 24 << endl;
	iPos = 0;
	for( i = 0; i < 26; i++ )
	{
		iMax = iMinCnt[ i ];
		for( j = 0; j < iMax; j++ )
		{
			lpOut[ iPos + j ] = 'a' + i;
		}

		iPos += iMax;
	}

	// 出力
	lpOut[ iPos ] = '\0';
	cout << lpOut << endl;

	return 0;
}


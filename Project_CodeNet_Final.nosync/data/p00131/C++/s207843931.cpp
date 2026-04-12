#include <iostream>
#include <cstring>
using namespace std;

class Board
{
public:
	Board()
	{
		memset( m_board, 0, sizeof(m_board) );
	}
	~Board()
	{
	}

	void input()
	{
		for( int i = 1; i < 11; ++i ){
			int bits = 0;
			for( int j = 0; j < 10; ++j ){
				bits <<= 1;
				int n;
				cin >> n;
				bits |= n;
			}
			m_board[ i ] = bits;
		}
	}
	void output()
	{
		for( int i = 0; i < 10; ++i ){
			int bit = 1 << 9;
			bool first = true;
			for( int j = 0; j < 10; ++j ){
				if( first ){
					first = false;
				}else{
					cout << " ";
				}
				cout << ( m_correct[ i ] & bit ? 1 : 0 );
				bit >>= 1;
			}
			cout << endl;
		}
	}
	bool light( int bits )
	{
		memset( m_correct, 0, sizeof(m_correct) );
		int board[ 12 ];
		memcpy( board, m_board, sizeof(m_board) );

		int mask = ( 1 << 10 ) - 1;
		for( int i = 1; i < 11; ++i ){
			m_correct[ i - 1 ] = bits;

			board[ i - 1 ] ^= bits; board[ i - 1 ] &= mask;
			board[ i + 1 ] ^= bits; board[ i + 1 ] &= mask;

			board[ i ] ^= bits;
			board[ i ] ^= ( bits << 1 );
			board[ i ] ^= ( bits >> 1 );
			board[ i ] &= mask;
			if( i > 1 && board[ i - 1 ] != 0 ){
				return false;
			}
			bits = board[ i ];
		}

		return board[ 10 ] == 0;
	}

private:
	int m_board[ 12 ];
	int m_correct[ 10 ];
};

int main()
{
	int n;

	while( cin >> n ){
		for( int i = 0; i < n; ++i ){
			Board board;
			board.input();

			for( int j = 0; j < ( 1 << 10 ); ++j ){
				if( board.light( j ) ){
					board.output();
					break;
				}
			}
		}
	}
	return 0;
}
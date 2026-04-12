#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define NONE -1

class Button
{
public:
	vector <int> pos;
	string link;

	Button()
	{
		Button( vector <int>(4,0), "" );
	}

	Button( vector <int> p1, string p2 )
	{
		pos = p1;
		link = p2;
	}
};

class Page
{
public:
	string title;
	vector <Button> buttons;

	Page()
	{
		Page( "", vector <Button>() );
	}

	Page( string p1, vector <Button> p2 )
	{
		title = p1;
		buttons = p2;
	}
};

int main( void )
{
	int n;
	while ( cin >> n && n > 0 )
	{
		// üÍ
		int W, H;
		cin >> W >> H;

		map <string,int> t2i;
		vector <Page> pages = vector <Page>( n );
		
		for ( int i = 0; i < n; i++ )
		{
			string title;
			int bs;

			// ^CgÆ{^ÌüÍ
			cin >> title >> bs;

			t2i[title] = i;

			vector <Button> buttons(bs);
			for ( int j = 0; j < bs; j++ )
			{
				// {^ÌÊuâNæðüÍ
				vector <int> pos(4);
				string link;
				for ( int lpc = 0; lpc < 4; lpc++ )
				{
					cin >> pos[lpc];
				}
				cin >> link;

				buttons[j] = Button( pos, link );
			}

			pages[i] = Page( title, buttons );

		}

		// ì
		int m;
		cin >> m;

		// »Ýn
		int cur = 0;
		// obt@[
		vector <int> buffer;
		buffer.push_back( cur );
		int bp = buffer.size() - 1;

		for ( int i = 0; i < m; i++ )
		{
			/*
			cout << "obt@ÌóÔ" << endl;
			for ( int i = 0; i < buffer.size(); i++ )
			{
				cout << buffer[i] << " ";
			}
			cout << endl;
			*/

			string cmd;
			cin >> cmd;

			if ( cmd == "click" )
			{
				// NbN
				int x, y;
				cin >> x >> y;

				vector <Button>& buttons = pages[cur].buttons;
				for ( vector <Button>::iterator it = buttons.begin(); it != buttons.end(); it++ )
				{

					Button b = *it;
					if ( b.pos[0] <= x && x <= b.pos[2] )
					{
						if ( b.pos[1] <= y && y <= b.pos[3] )
						{
							// Nµ½

							// obt@[XV
							if ( bp != -1 && bp < buffer.size() - 1 )
							{
								// bpÍOÌÙ¤ð©Ä¢é
								// bpæèÃ¢àÌðc·
								vector <int> new_buffer;
								new_buffer.assign( buffer.begin(), buffer.begin()+bp+1 );
								// cout << "update buffer: " << bp << " " << new_buffer.size() << endl;
								buffer = new_buffer;
							}

							int next = t2i[ b.link ];

							buffer.push_back( next );
							bp = buffer.size() - 1; // êÔVµ¢vf
							
							cur = next;
							break;
						}
					}
				}
			}
			else if ( cmd == "back" )
			{
				// OÌy[WÉßé
				if ( bp != -1 && buffer.size() > 0 )
				{
					if ( bp > 0 )
						bp--;
					cur = buffer[bp];
				}
			}
			else if ( cmd == "forward" )
			{
				// Ìy[WÉiÞ
				if ( bp != -1 && buffer.size() > 0 )
				{
					if ( bp < buffer.size() - 1 )
						bp++;
					cur = buffer[bp];
				}
			}
			else if ( cmd == "show" )
			{
				cout << pages[cur].title << endl;
			}

		}

	}

	return 0;
}
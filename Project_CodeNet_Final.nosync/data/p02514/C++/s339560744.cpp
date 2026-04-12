#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BUTTON
{
	int x1, y1, x2, y2;
	string target;
};

struct PAGE
{
	string title;
	vector<BUTTON> button;
};

using namespace std;

int main()
{
	while ( true )
	{
		int n;
		cin >> n;
		if ( n == 0 )
			break;

		int W, H;
		cin >> W >> H;

		vector<PAGE> page(n);
		for ( int i=0; i<n; i++ )
		{
			int bn;
			cin >> page[i].title >> bn;

			for ( int j=0; j<bn; j++ )
			{
				BUTTON b;
				cin >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> b.target;
				page[i].button.push_back( b );
			}
		}

		int m;
		cin >> m;

		int cur = 0;
		vector<int> hist( 1, 0 );

		while ( --m >= 0 )
		{
			string cmd;
			cin >> cmd;

			if ( cmd == "click" )
			{
				int x, y;
				cin >> x >> y;

				vector<BUTTON> &button = page[hist[cur]].button;
				string target = "";
				for ( int i=0; i<(int)button.size(); i++ )
					if ( button[i].x1 <= x  &&  x <= button[i].x2  &&
						 button[i].y1 <= y  &&  y <= button[i].y2 )
						target = button[i].target;

				int ti = -1;
				for ( int i=0; i<n; i++ )
					if ( page[i].title == target )
						ti = i;
				if ( ti >= 0 )
				{
					hist.resize( cur+1 );
					hist.push_back( ti );
					cur++;
				}
			}
			if ( cmd == "back" )
			{
				if ( cur > 0 )
					cur--;
			}
			if ( cmd == "forward" )
			{
				if ( cur < (int)hist.size() - 1 )
					cur++;
			}
			if ( cmd == "show" )
			{
				cout << page[hist[cur]].title << endl;
			}
		}
	}

	return 0;
}

				
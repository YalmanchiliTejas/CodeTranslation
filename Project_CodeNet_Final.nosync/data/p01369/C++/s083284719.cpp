#include <iostream>
#include <string>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for(int i = m; i < (n); ++i)

int main()
{
	char right[] = { 'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm' };
	string str;
	
	while(cin >> str && str != "#")
	{
		int ans = 0;
		bool r = false;
		rep(i, 11) if(str[0] == right[i]) r = true;
		
		rep2(i, 1, str.size())
		{
			bool rr = false;
			rep(j, 11) if(str[i] == right[j]) rr = true;
			if(r != rr)
				r = rr, ++ans;
		}
		
		cout << ans << endl;
	}
}
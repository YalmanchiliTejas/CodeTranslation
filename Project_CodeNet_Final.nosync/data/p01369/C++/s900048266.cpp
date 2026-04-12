// AOJ 2252 (http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2252)
#include<iostream>
#include<string>
#define rep(i,a) for(int i=0;i<(a);++i)
#define notFound(c) (lhs.find(c)==std::string::npos)

const std::string lhs = "qwertasdfgzxcvb";

int main()
{
	std::string s;
	while( std::cin >> s, s != "#" )
	{
		int ans = 0;

		rep( i, s.size()-1 )
			ans += notFound(s[i+1])!=notFound(s[i]);
	
		std::cout << ans << std::endl;
	}

	return 0;
}
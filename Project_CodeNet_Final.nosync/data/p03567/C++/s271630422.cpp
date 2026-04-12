#include<iostream>
#include<algorithm>
#include<string>


using namespace std;


bool contains(const std::string& str1, const std::string& str2)
{
	std::string::size_type pos = str1.find(str2);
	if (pos == std::string::npos)
	{
		return false;
	}
	return true;
}


int main()
{

	string S, s;

	cin >> S;

	if (contains(S, "AC"))s = "Yes";
	else s = "No";

	cout << s << endl;

	return 0;
}



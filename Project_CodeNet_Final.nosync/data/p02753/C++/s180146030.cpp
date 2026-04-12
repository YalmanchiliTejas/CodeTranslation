#include <iostream>
using namespace std;
int main (void)
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	string s;
	cin >> s;
	bool bus = false;
	if(s[0] != s[1] || s[0] != s[2] || s[1] != s[2])
		bus = true;
    if(bus == true)
		cout << "Yes\n";
	else 
		cout << "No\n";
    return 0;
}
// date_time : 15.03.2020 16:54:07 IST 
// Author : Aditya Kumar Maurya <adityakrmaurya03@gmail.com>
// “ Code is like humor. When you have to explain it, it’s bad.” – Cory House

#include<iostream>
#include<string>

int main(int argc, char const* argv[])
{
	using namespace std;
	
	
		
	int n;
	string s;
	int k;
	cin >> n >> s >> k;

	const char& sk = s[k-1];
	for (auto& c : s) {
		if(sk==c){
		}
		else{
			c='*';
		}
	};
	
	cout << s << endl;
  
	return 0;
}
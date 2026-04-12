    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <string.h>
     
    typedef long long ll;
    using namespace std;
    const ll INF = 1000000000000000000ll;
    const ll MOD = 1000000007ll;
     
    const double EPS = 1e-8;
     
    int main()
    {
   		char c;

		cin >> c;

		if(c=='a' || c=='i' ||c=='u' ||c=='e' ||c=='o' ){
			cout << "vowel" << endl;
		}else{
			cout << "consonant" << endl;
		}

		
		return 0;
    }
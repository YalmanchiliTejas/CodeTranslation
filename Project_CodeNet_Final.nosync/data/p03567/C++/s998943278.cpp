    #include<iostream>
    #include<cstdio>
    #include<math.h>
    #include<string>
    #include<algorithm>
    #include<functional>
    #include<vector>
    #include<set>
    #include<map>
    #define INF 999999
    #define EPS 1.0e-6
     
    using namespace std;
     
    typedef long long ll;
    typedef pair<int, int> P;
    typedef pair<int, P> PP;
     
    string s;
     
    int main()
    {
    	cin >> s;
     
    	int ope = 0;
    	for (int i = 0; i < s.length()-1; i++) {
    		if (s[i] == 'A') {
    			if (s[i + 1] == 'C') {
    				ope++;
    			}
    		}
    	}
    	if (ope != 0)cout << "Yes" << endl;
    	else cout << "No" << endl;
     
    	return 0;
    }
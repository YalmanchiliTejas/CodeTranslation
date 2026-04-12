    #include<iostream>
    #include<string>
    #include<vector>
    #include<math.h>
    #include<cmath>
    #include<stack>
    //#include<stdlib.h>
    using namespace std;
    int main() {
    	int n,k; string s;
    	cin>> n>>s>>k;k--;
      for(int a=0;a<n;a++){if(s[a]!=s[k]){s[a]='*';}}
      cout<<s;
      return 0;}
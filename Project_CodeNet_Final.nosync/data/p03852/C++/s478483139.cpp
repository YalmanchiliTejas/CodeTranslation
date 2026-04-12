#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
char c;
int main()
{
	cin>>c;
    if(c=='a'||c=='e'||c=='o'||c=='i'||c=='u') cout<<"vowel";
    else cout<<"consonant";
	return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;
//ifstream cin();
//ofstream cout();
char c;
int main(){
	c=getchar();
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')cout<<"vowel\n";
    else cout<<"consonant\n";
	ios::sync_with_stdio(false);
	return 0;
}

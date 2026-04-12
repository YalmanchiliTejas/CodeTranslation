#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<vector>
#include<cstdlib>
using namespace std;
#define y printf("vowel")
#define n printf("consonant")
#define b break
char ch;
int main(){
	cin>>ch;
	switch(ch){
		case 'a':y;b;
		case 'e':y;b;
		case 'i':y;b;
		case 'o':y;b;
		case 'u':y;b;
		default:n;
	}
    return 0;
}
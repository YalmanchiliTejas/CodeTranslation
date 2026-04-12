#include<bits/stdc++.h>
using namespace std;
const int a[]={0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
char ch;
int main()
{
	ch=getchar();
	if(a[ch-'a'+1]) cout<<"vowel";
	else cout<<"consonant";
	return 0;
}
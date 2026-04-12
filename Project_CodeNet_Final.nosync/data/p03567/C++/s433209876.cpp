#include <iostream>
#include <stdio.h>

int main()
{
using namespace std;
string S;
cin >> S;
int flag = 0;
for(int i=0;i<(S.size());i++)
{
if(S.substr(i,2) == "AC")
{
flag = 1;
}
}
if(flag == 1)
{
cout << "Yes" << endl;
}else{
cout << "No" << endl;
}
}

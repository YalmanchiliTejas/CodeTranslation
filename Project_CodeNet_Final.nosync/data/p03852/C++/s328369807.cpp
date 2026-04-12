/*************************************************************************
	> File Name: 49a.cpp
	> Author: SIU
	> Created Time: 2016年12月10日 星期六 20时04分16秒
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a;
    scanf("%c",&a);
    if(a=='a'||a=='i'||a=='e'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
    printf("vowel\n");
else 
    printf("consonant\n");
    return 0;
}

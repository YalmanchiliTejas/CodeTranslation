#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    
    x=x-z;
    printf("%d",(x/(y+z)));
	return 0;
}
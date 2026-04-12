#include<bits/stdc++.h>

using namespace std;

int main() {
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
        printf("%s\n",[&]() {
			if(a>b) return "a > b";
			else if(a<b) return "a < b";
			else return "a == b";
		}());

    return 0;
}
#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d" , &n);
	printf("%d\n" , n * 800 - (n / 15) * 200);
}
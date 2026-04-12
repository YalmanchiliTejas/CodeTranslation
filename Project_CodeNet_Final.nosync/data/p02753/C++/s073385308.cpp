#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	char a = getchar(), b = getchar(), c = getchar();
	getchar(); // Get the '\n'
	puts((a == b && b == c && a == c)? "No": "Yes");
	return 0;
}
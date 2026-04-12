#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n = 5;
int w = 4;
int t = 1;
int tmp;

int right()
{ 
    tmp = n;
    n = w;
    w = 7 - tmp;
    return t;
}
int left()
{
    tmp = w;
    w = n;
    n = 7 - tmp;
    return t;
}
int north()
{
    tmp = n;
    n = t;
    t = 7 - tmp;
    return t;
}
int east()
{
    tmp = t;
    t = w;
    w = 7 - tmp;
    return t;
}
int west()
{
    tmp = w;
    w = t;
    t = 7 - tmp;
    return t;
}
int south()
{
    tmp = t;
    t = n;
    n = 7 - tmp;
    return t;
}
 
int main()
{
    int row;
	
    while (cin >> row, row) {
        int sum = 1;
        n = 5;
        w = 4;
        t = 1;
        string str;
		
        for (int i = 0; i < row; i++) {
            cin >> str;
            if (str == "North") sum += north();
            if (str == "South") sum += south();
            if (str == "West") sum += west();
            if (str == "East") sum += east();
            if (str == "Right") sum += right();
            if (str == "Left") sum += left();
        }
        cout << sum << endl;
    }
    return 0;
}
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int top, south, east;
    int n;
    int ans;
    string action;

    while (scanf("%d", &n) * n != 0){
        top = 1;
        south = 2;
        east = 3;
        ans = 1;

        for (int i = 0; i < n; i++){
            cin >> action;

            if (action == "North"){
                swap(top, south);
                south = 7 - south;
            }
            if (action == "East"){
                swap(top, east);
                top = 7 - top;
            }
            if (action == "West"){
                swap(top, east);
                east = 7 - east;
            }
            if (action == "South"){
                swap(top, south);
                top = 7 - top;
            }
            if (action == "Right"){
                swap(east, south);
                east = 7 - east;
            }
            if (action == "Left"){
                swap(east, south);
                south = 7 - south;
            }

            ans += top;
        }
        printf("%d\n", ans);
    }
    return (0);
}
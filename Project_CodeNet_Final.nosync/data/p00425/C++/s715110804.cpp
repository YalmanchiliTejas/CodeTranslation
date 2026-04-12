#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    while (cin >> n && n != 0) {
        int sum = 1;
        int top=1, bottom=6, left=4, right=3, front=2, back=5;
        for (int i=0; i<n; ++i) {
            string direction;
            cin >> direction;
            int tmp;
            if (direction == "North") {
                tmp=top;
                top=front; front=bottom; bottom=back; back=tmp;
            } else if (direction == "East") {
                tmp=top;
                top=left; left=bottom; bottom=right; right=tmp;
            } else if (direction == "West") {
                tmp=top;
                top=right; right=bottom; bottom=left; left=tmp;
            } else if (direction == "South") {
                tmp=top;
                top=back; back=bottom; bottom=front; front=tmp;
            } else if (direction == "Right") {
                tmp=front;
                front=right; right=back; back=left; left=tmp;
            } else if (direction == "Left") {
                tmp=front;
                front=left; left=back; back=right; right=tmp;
            }
            sum += top;
        }
        cout << sum << endl;
    }
    return 0;
}
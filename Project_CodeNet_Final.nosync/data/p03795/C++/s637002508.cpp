#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // 整数の入力
    int N,x,y;
    cin >> N;

    x = 800 * N;
    y = 200 * (int)(N / 15);

  	cout << x -y << endl;
    return 0;
}
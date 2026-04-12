#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    // あとで消す
    //std::ifstream in("ain3.txt");
    //std::cin.rdbuf(in.rdbuf());

    string N,M;
    cin >> N >> M;

    string judge = (N==M) ? "Yes" : "No" ;

    cout << judge << endl;

    return 0;
}

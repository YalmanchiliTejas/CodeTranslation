#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::pair;

using std::vector;
using std::sort;
using std::lower_bound;
using std::upper_bound;
using std::find_if;
using std::copy;
using std::copy_if;

int main(){
    int x,y,z;
    cin >> x;
    cin >> y;
    cin >> z;

    x-=z;
    int count=-1;
    do{
        x-=y;
        x-=z;
        count++;
    }while(x>=0);

    cout << count << endl;
    return 0;
}


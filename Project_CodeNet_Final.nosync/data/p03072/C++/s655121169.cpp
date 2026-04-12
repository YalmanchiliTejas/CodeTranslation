#include <iostream>
using namespace std;

int main()
{
    int num, highest=0, count=0, current;
    cin >> num;
    for(int i=0; i< num;i++){
        cin >> current;
        if(current >= highest){
            count ++;
            highest = current;
        }
    }
    cout << count << endl;
    return 0;
}
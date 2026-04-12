#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    int h[N];
    int i;
    int max =0;
    int count = 0;
    for(i=0;i<N;i++)
    {
        cin >> h[i] ;
        if(h[i] >= max)
        {
            max = h[i];
            count ++;
        }
    }
    cout << count << endl;
    return 0;
    
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    int H[20];
    int counter = 1;
    bool view_flag = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }

    for (int i = 1; i < n; i++) {
        
        for (int j = 0; j < i; j++) {
            if (H[i] - H[j] < 0) {
                view_flag = false;
            }
        }

        if (view_flag == true) {
            counter+=1;
        }

        view_flag = true;
        
    }
     

    cout << counter << endl;

}
#include <iostream>

using namespace std;

int main()
{
    int counter=0;
    char A[5]={'a','e','o','i','u'};
    char c;
    cin >> c;
    for (int i=0; i<5; i++){
        if (c==A[i]){
            counter+=1;
        }
    }
    if (counter==1){
        cout << "vowel";
    }
    else {
        cout << "consonant";
    }

    return 0;
}


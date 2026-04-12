#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

int main()
{
    // get a integer
    char c;
    cin >> c ;

    char vowels[] = {'a', 'i', 'u', 'e', 'o'};

    for (auto&& i = 0; i < 5; ++i ) {
        if( vowels[i] == c )
        {
            cout << "vowel" << endl; 
            return 0;
        }
    }

    cout << "consonant" << endl;
}


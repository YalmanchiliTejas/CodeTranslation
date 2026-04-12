#include<iostream>
#include <algorithm>

using namespace std;

int main(){
 char letter;
 cin >> letter;
 char alphabet[5] = {'a', 'e', 'i', 'o', 'u'};

    if (find(begin(alphabet), end(alphabet), letter) != end(alphabet))
        cout << "vowel";
    else
        cout << "consonant";

  //system("pause");
  return 0;
}
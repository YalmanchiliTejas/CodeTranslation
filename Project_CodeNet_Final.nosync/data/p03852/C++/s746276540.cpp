#include <iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define INF 0x3f //plus infinite


int main(){
  string set = "aeiou";
  string c ;
  cin >> c;
  
  for(int i = 0;i < set.size() ;i++){
    if(c.at(0) == set.at(i)){
      cout << "vowel" << endl;
      return 0;
    }
  }
  
  cout << "consonant" << endl;
  return 0;
}

/*文字列の辞書順について
 *C++の順序では'0'～'9'→'A'～'Z'→'a'～'z'の順に
 *                       なっていることに注意しましょう。
 */

/*行単位での入力
 * getline(cin,文字列変数);
 */

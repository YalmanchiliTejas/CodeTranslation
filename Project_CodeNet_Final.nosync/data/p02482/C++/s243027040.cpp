#include<iostream>

using namespace std;

/*
lambda解説
[] // [lambda-capture] | キャプチャー & か = を宣言、　変数ごとに使用可能
() // (parameter-declaration-clause) | 引数 (int a = 3) みたいに初期値設定も可能、引数がない場合省略可能
{} // compound-statement       | この中に処理を書く
() // Function call expression | これを付けることで定義したlambdaを呼び出す
;
定義 : [](引数)->戻り値{処理}
定義と共に呼び出し : [](引数)->戻り値{処理}()
*/

struct MyName{
  string name;
  MyName(string name="noname"):name(name){}
};
int test(int a){
  return a*a*a;
}

int main(){
  /*
  auto func = [](int a=3)->int{cout << a*a << " = YES" << endl; return test(100);};
  cout << func(2) << endl;

  auto func2 = [](string name="chida")->MyName{return MyName(name);};
  cout << func2("nariyoshi").name << endl;
  cout << func2().name << endl;
  */

  /*
    [&](){}; //このlambdaが定義されている関数内のスコープにある変数をlambda内で参照として使うことができる　参照なので、lambda内で呼び出し元の関数内の変数を変更した場合、その変更はlambdaをでても適用される

    [=]()mutable{}; //このlambdaが定義されている関数内のスコープにある変数をlambda内でコピーとして使うことができる　コピーなので、lambda内での変更は呼び出し元の関数内の変数には影響を与えない ちなみにlambdaの関数の呼び出し演算子はconst修飾されているらしいのでmutableとつけないとエラーになる 戻り値がある場合はその前にmutableを宣言する　[=]()mutable -> 戻り値{};

   */

  /*
  string text = "lambda is this.";
  cout << "Before : " << text << endl;
  //[](string& s){s = "change";}(text);
  string add = " added";
  //[&](const string& s){text += s;}(add);
  //[=](const string& s)mutable{text += s;}(add);
  //[=](string s)mutable{text += s;}(add);
  cout << "After  : " << text << endl;
  */

  /*
  unsigned long long x=-1;
  auto func = [&]()->unsigned long long{return x*x*x;};
  [&](){cin >> x; cout << func() << endl;}();
  */

  int a,b;
  [=]()mutable{cin >> a >> b; [&](){
      int res;
      auto func1 = [](int A,int B)->bool{return A == B;};  
      auto func2 = [&]()->bool{return a > b;};
      auto func3 = [=]()mutable->bool{return a < b;};

      [&](){
	if(func1(a,b))cout << "a == b" << endl;
	if(func2())cout << "a > b" << endl;
	if(func3())cout << "a < b" << endl;
      }();

    }(); }();

 return 0;
}
#include <iostream>
#include <string>
#include <vector>
#define PB push_back
using namespace std;
int MF(string str)
{
  vector<int> ans;
  ans.PB(str[0]-'0');
  for(int i=1;i<str.size();i+=2){
    if(str[i]=='*')
      ans[ans.size()-1]*=str[i+1]-'0';
    else ans.PB(str[i+1]-'0');
  }
  int answer=0;
  for(int i=0;i<ans.size();++i)
    answer+=ans[i];
  return answer;
}
int LF(string str)
{
  int answer;
  answer=str[0]-'0';
  for(int i=1;i<str.size();i+=2){
    if(str[i]=='*')
      answer*=str[i+1]-'0';
    else answer+=str[i+1]-'0';;
  }
  return answer;
}
int main(void)
{
  string line;
  int canans;
  cin >> line;
  cin >> canans;
  int tmp=0;
  if(MF(line)==canans) tmp+=1;
  if(LF(line)==canans) tmp+=2;
  string answer[4]={"I","M","L","U"};
  cout << answer[tmp] << endl;
  return 0;
}
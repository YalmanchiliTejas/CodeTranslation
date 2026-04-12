#include <iostream>
#include <vector>
#include <set>
int main()
{
  int H, W;
  std::cin >> H >> W;
  std::vector<std::vector<char> > A(H, std::vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++) std::cin >> A.at(i).at(j);
  }
  std::set<int> deleteH, deleteW;
  bool is_all_blank;
  for (int i = 0; i < H; i++)
  {
    is_all_blank = true;
    for (int j = 0; j < W; j++)
    {
      if (A.at(i).at(j) == '#')
      {
        is_all_blank = false;
        break;
      }
    }
    if (is_all_blank) deleteH.insert(i);
  }
  for (int i = 0; i < W; i++)
  {
    is_all_blank = true;
    for (int j = 0; j < H; j++)
    {
      if (A.at(j).at(i) == '#')
      {
        is_all_blank = false;
        break;
      }
    }
    if (is_all_blank) deleteW.insert(i);
  }
  for (int i = 0; i < H; i++)
  {
    if (deleteH.find(i) != deleteH.end()) continue;
    for (int j = 0; j < W; j++)
    {
      if (deleteW.find(j) != deleteW.end()) continue;
      std::cout << A.at(i).at(j);
    }
    std::cout << std::endl;
  }
}

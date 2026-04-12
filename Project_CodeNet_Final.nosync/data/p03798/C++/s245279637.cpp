#include <iostream>
#include <assert.h>
#include <vector>

bool check_consistency(std::vector<bool>& res, std::vector<bool>& ans) {
  for (int32_t i = 1; i < (int32_t)ans.size() - 1; i++) {
    if (res[i] && ans[i]) res[i+1] = res[i-1];//sheep 'o'
    else if (res[i] && !ans[i]) res[i+1] = !res[i-1]; //sheep 'x'
    else if (!res[i] && ans[i]) res[i+1] = !res[i-1]; //wolf 'o'
    else res[i+1] = res[i-1]; //wolf 'x'
  }
  bool first_elem;
  if (res.back() && ans.back()) first_elem = *(res.end() - 2);//sheep 'o'
  else if (res.back() && !ans.back()) first_elem = !(*(res.end() - 2));//sheep 'x'
  else if (!res.back() && ans.back()) first_elem = !(*(res.end() - 2));//wolf 'o'
  else first_elem = *(res.end() - 2);//wolf 'x'

  if (first_elem != res[0]) {
    return false;
  } else {
    bool second_elem;
    if (res[0] && ans[0]) second_elem = res.back();//sheep 'o'
    else if (res[0] && !ans[0]) second_elem = !res.back(); //sheep 'x'
    else if (!res[0] && ans[0]) second_elem = !res.back(); //wolf 'o'
    else second_elem = res.back(); //wolf 'x'
    return (second_elem == res[1]);
  }
}

void dump_res(std::vector<bool>& res) {
  for (auto i : res) {
    char animal = i? 'S' :'W';
    std::cout << animal;
  }
  std::cout << std::endl;
  return;
}

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int32_t N;
  std::cin >> N;;
  std::vector<bool> ans_vect(N); // 'o': True
  for (int32_t i = 0; i< N; i++) {
    char tmp;
    std::cin >> tmp;
    ans_vect[i] = tmp == 'o'? true : false;
  }

  std::vector<bool> pattern(N); //Sheep: True, Wolf: False
  //pattern 1 ... patten[0] = Sheep, pattern[1] = sheep
  pattern[0] = true;
  pattern[1] = true;
  if (check_consistency(pattern, ans_vect)) {
    dump_res(pattern);
    return 0;
  }
  //pattern 2 ... patten[0] = Sheep, pattern[1] = wolf
  pattern[0] = true;
  pattern[1] = false;
  if (check_consistency(pattern, ans_vect)) {
    dump_res(pattern);
    return 0;
  }
  //pattern 3 ... patten[0] = wolf, pattern[1] = sheep
  pattern[0] = false;
  pattern[1] = true;
  if (check_consistency(pattern, ans_vect)) {
    dump_res(pattern);
    return 0;
  }
  //pattern 4 ... patten[0] = wolf, pattern[1] = wolf
  pattern[0] = false;
  pattern[1] = false;
  if (check_consistency(pattern, ans_vect)) {
    dump_res(pattern);
    return 0;
  }
  std::cout << -1 << std::endl;
  return 0;
}

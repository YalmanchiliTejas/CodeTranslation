N, X, M = map(int, input().split())
from collections import defaultdict
check = defaultdict(int)
L = [0,X]
L_ans = [0,X]
roop_end = 0

ans = X

old_a = X
for i in range(2,N+1):
  a = (old_a**2)%M
  ans += a
  old_a = a
  L.append(a)
  L_ans.append(ans)
  
  if check[a] != 0:
    roop_first = check[a]
    roop_end = i
    roop_iter = roop_end - roop_first
    ans = L_ans[roop_first - 1]
    roop_first_ans = L_ans[roop_first]
    roop_end_ans = L_ans[roop_end]
    roop_plus = roop_end_ans - roop_first_ans
    break
  else:
    check[a] = i
if roop_end == 0:
  print(ans)
else:
  roop_phase = N - roop_first + 1
  roop_num = roop_phase // roop_iter
  ans += roop_plus * roop_num
  roop_addition = roop_phase % roop_iter
  addition = L_ans[roop_first - 1 + roop_addition] - L_ans[roop_first - 1]
  ans += addition
  print(ans)
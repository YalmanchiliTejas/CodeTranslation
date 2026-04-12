import sys
sys.setrecursionlimit(1000000)
n, x = map(int, input().split())
layers = [1]
pats = [1]
cnt = 1
p_cnt = 1
for _ in range(n):
  cnt = cnt * 2 + 3
  p_cnt = p_cnt * 2 + 1
  layers.append(cnt)
  pats.append(p_cnt)
def solve(lev, rest):
  if rest == 0:
    return 0
  if lev == 0:
    return 1
  if rest - 1 <= layers[lev - 1]:
    return solve(lev - 1, rest - 1)
  elif rest - 1 == layers[lev - 1]:
    return pats[lev - 1] + 1
  else:
    return pats[lev - 1] + 1 + solve(lev - 1, rest - 1 - layers[lev - 1] - 1)

print(solve(n, x))
import math
n = int(input())
s = input()

m = {
  'S': {
    'S': {'o': 'S', 'x': 'W'},
    'W': {'o': 'W', 'x': 'S'},
  },
  'W': {
    'S': {'o': 'W', 'x': 'S'},
    'W': {'o': 'S', 'x': 'W'},
  }
}
import itertools
for p, c in itertools.product(['S','W'], ['S','W']):
  ans = [p, c]
  for a in s:
    p,c = c, m[p][c][a]
    ans.append(c)
  if ans[:2] == ans[-2:]:
    print(''.join(ans[1:-1]))
    exit(0)
print(-1)
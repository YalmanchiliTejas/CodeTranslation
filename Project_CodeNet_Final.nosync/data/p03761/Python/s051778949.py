from collections import Counter

N = int(input())
S = [Counter(input()) for _ in range(N)]
aplhabet = 'abcdefghijklmnopqrstuvwxyz'

ans = ''
for a in aplhabet:
  a_min = float('inf')
  for s in S:
    a_min = min(a_min, s[a])
  ans += a * a_min

print(ans)
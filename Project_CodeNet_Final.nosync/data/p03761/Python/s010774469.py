from collections import Counter
from math import ceil
N = int(input())
S = [input() for _ in range(N)]
s = S[0]
for i in range(1,N):
  s += S[i]
  s = ''.join([key*(min(val//2,s.count(key)-S[i].count(key))) for key,val in Counter(s).items() if val > 1])
s = sorted(s)
print(''.join(s))
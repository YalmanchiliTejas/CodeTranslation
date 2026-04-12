import string
import collections

N = int(input())
S = [input() for _ in range(N)]
max_str = collections.Counter(S[0])
for i in range(N-1):
  tmp = collections.Counter(S[i+1])
  #print(tmp)
  for k, v in max_str.items():
    if k in tmp:
      max_str[k] = min(v, tmp[k])
    else:
      max_str[k] = 0
#print(max_str)
ans = ""
for k, v in sorted(max_str.items()):
  ans += k * v
print(ans)

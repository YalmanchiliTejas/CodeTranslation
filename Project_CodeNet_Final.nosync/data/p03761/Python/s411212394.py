from collections import Counter
n = int(input())
S = [input() for _ in range(n)]

ans = Counter(S[0])
for i in range(1,n):
  tmp = Counter(S[i])
  for a in ans.keys():
    if a in tmp:
      ans[a] = min(ans[a],tmp[a])
    else:
      ans[a] = 0
x = ''
for a in ans.items():
  x += a[0]*a[1]
print(''.join(sorted(x)))
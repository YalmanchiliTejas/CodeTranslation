from collections import Counter
n = int(input().strip())
S = [input().strip() for _ in range(n)]
s = Counter(S[0])
for i in range(1,n):
  s = s & Counter(S[i])
ans = ''
for k,v in s.items():
  ans += k*v
print(''.join(sorted(ans)))

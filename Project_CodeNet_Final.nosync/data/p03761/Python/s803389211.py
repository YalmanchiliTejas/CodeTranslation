n = int(input())
alpha = list('abcdefghijklmnopqrstuvwxyz')
num_s = dict(zip(alpha, [50]*len(alpha)))

for i in range(n):
  S = input()
  d = dict(zip(alpha, [0]*len(alpha)))
  for s in S:
    d[s] += 1
  for s in d:
    num_s[s] = min(num_s[s], d[s])

ans = ''
for s in num_s:
  ans += s*num_s[s]

print(''.join(sorted(ans)))
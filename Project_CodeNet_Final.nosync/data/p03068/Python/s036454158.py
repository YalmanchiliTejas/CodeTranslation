N = int(input())
S = input()
K = int(input())
ans = ''
for s in S:
  if s == S[K-1]:
    ans += s
  else:
    ans += '*'
print(ans)
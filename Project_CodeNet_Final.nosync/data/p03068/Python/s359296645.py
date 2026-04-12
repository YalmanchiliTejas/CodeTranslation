N = int(input())
S = input()
K = int(input())

kc = S[K - 1]
ans = ''
for c in S:
  if c != kc:
    ans += '*'
  else:
    ans += c

print(ans)
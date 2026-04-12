N = int(input())
S = input()
K = int(input())

target = S[K - 1]
ans = ''
for i in range(N):
  if S[i] != target:
    ans += '*'
  else:
    ans += S[i]
print(ans)

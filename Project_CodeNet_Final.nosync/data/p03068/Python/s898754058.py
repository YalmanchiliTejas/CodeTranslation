N = int(input())
S = input()
K = int(input())
T = S[K-1]
ans = ''
for i in range(N):
  if S[i] == T:
    ans += T
  else:
    ans += '*'
print(ans)
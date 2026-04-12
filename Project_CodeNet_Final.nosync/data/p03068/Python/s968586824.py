N = int(input())
S = list(input())
K = int(input())

moji = S[K-1]
for i in range(N):
  if S[i]!=moji:
    S[i]="*"
ans = ''.join(S)
print(ans)
N = int(input())
S = list(input())
K = int(input())
lit = S[K-1]
for i in range(N):
  if S[i] != lit:
    S[i] = '*'
print(''.join(S))
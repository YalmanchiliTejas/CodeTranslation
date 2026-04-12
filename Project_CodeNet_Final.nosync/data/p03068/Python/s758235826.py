N = int(input())
S = list(input())
K = int(input())

tgt = S[K-1]
for i in range(N):
  if( S[i] != tgt ):
    S[i] = "*"
print("".join(S))

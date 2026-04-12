N,S,K=int(input()),list(input()),int(input())
for i in range(N):
  if S[i] != S[K-1]:
    S[i]='*'
print("".join(S))
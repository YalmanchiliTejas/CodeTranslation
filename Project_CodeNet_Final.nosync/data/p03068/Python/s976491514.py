N=int(input())
S=str(input())
K=int(input())
W=S[K-1]
for i in range(N):
  if S[i]!=W:
    S=S.replace(S[i],'*')
print(S)
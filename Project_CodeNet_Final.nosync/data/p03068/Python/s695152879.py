N=int(input())
Sl=input()
K=int(input())
S= list(Sl)
for i in range(N):
 if S[i]  != S[K-1]:
  ass = '*'
  S[i] = ass
Snew = "".join(S)
print(Snew)
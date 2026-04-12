N=int(input())
S=list(input())
ks=S[int(input())-1]
for i in range(N):
  if S[i]!=ks:
    S[i]='*'
print(''.join(S))
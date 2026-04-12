N=int(input())
S=input()
K=int(input())
s=S[K-1]
for i in range(0,N):
  if S[i]!=s:
    S=S.replace(S[i],'*')
    
    
print(S)
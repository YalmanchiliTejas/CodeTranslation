N=int(input())
S=input()
K=int(input())
c=S[K-1]
ans=list('*'*N)
for i in range(N):
    if S[i]==c:
        ans[i]=c
print(''.join(ans))

N=int(input())
S=input()
K=int(input())

ans=''
for i in range(N):
    if S[i]!=S[K-1]:
        ans=ans+'*'
    else:
        ans=ans+S[i]
print(ans)
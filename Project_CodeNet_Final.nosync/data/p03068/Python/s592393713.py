N=int(input())
S=input()
K=int(input())
c0=S[K-1]
ans=''
for c in S:
    if c==c0:
        ans+=c0
    else:
        ans+='*'

print(ans)
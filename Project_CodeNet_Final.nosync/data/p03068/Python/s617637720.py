input()
S=input()
k=int(input())
l=S[k-1]
ans=''
for s in S:
    if s==l:
        ans+=s
    else:
        ans+='*'
print(ans)
n=int(input())
s=list(input())
k=int(input())

e=s[k-1]

ans=''
for i in range(n):
    if s[i]==e:
        ans+=e
    else:
        ans+='*'
print(ans)
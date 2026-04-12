input()
s=input()
k=int(input())
A=s[k-1]
ans=''
for i in s:
    if i==A:
        ans+=A
    else:
        ans+='*'
print(ans)
n=int(input())
s=input()
k=int(input())

ans=''
for x in s:
    if x!=s[k-1]:
        ans=ans+'*'
    else:
        ans=ans+s[k-1]
print(ans)
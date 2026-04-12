n=int(input())
s=input()
k=int(input())
m=s[k-1]
ans=""
for i in range(n):
    if s[i]==m:
        ans+=m
    else:
        ans+='*'
print(ans)
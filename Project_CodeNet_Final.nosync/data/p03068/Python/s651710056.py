n=int(input())
s=input()
k=int(input())
k-=1
x=s[k]
ans=""
for i in range(n):
    if s[i]!=x:
        ans+="*"
    else:
        ans+=x
print(ans)

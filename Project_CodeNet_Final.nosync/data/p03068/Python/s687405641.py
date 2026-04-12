n=int(input())
s=input()
k=int(input())-1
t=s[k]
ans=""
for i in range(n):
    if s[i]!=t:
        ans+="*"
    else:
        ans+=s[i]
print(ans)
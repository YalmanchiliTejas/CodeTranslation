n=int(input())
s=input()
k=int(input())
t=s[k-1]
ans=""
for i in s:
    if i==t: ans+=i
    else: ans+="*"

print(ans)

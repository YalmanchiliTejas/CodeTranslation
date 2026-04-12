n,s,k=[input() for _ in range(3)]
n,k=int(n),int(k)
ans=""
for i in s:
    if i!=s[k-1]:
        ans+="*"
    else:
        ans+=i
print(ans)
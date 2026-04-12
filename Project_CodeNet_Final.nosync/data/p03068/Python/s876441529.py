n,s,k=int(input()),input(),int(input())
t=s[k-1]
ans=""
for i in range(n):ans+=(t if s[i]==t else "*")
print(ans)
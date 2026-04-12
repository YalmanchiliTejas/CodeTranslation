n=int(input())
s=input()
k=int(input())
r=s[k-1]
ans=""
for i in range(n):
  if s[i]==r:
    ans+=r
  else:
    ans+="*"
print(ans)
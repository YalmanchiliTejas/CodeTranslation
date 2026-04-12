n=int(input())
s=input()
k=int(input())
v=s[k-1]
ans=""
for i in range(n):
  if s[i]==v:
    ans+=v
  else:
    ans+="*"
print(ans)
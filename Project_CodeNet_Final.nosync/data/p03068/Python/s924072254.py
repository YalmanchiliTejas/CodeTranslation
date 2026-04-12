n=int(input())
s=input()
k=int(input())

c=s[k-1]
ans=""
for i in s:
  if i==c:
    ans+=c
  else:
    ans+="*"
print(ans)
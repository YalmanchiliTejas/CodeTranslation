n=int(input())
s=input()
k=int(input())
a=s[k-1]
ans=""
for i in s:
  if i==a:
    ans+=a
  else:
    ans+="*"
print(ans)
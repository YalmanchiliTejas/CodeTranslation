n=int(input())
s=input()
k=int(input())
ans=''
for i in s:
  if i == s[k-1]:
    ans+=i
  else:
    ans+='*'
print(ans)
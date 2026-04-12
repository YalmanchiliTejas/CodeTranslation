n=int(input())
s=input()
k=int(input())
a=s[k-1]
ans=''
for x in s:
  if x!=a:
    ans+='*'
  else:
    ans+=x
print(ans)
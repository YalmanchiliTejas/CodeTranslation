n=int(input())
s=input()
k=int(input())
check=s[k-1]
ans=''
for i in range(n):
  if s[i]==check:
    ans+=s[i]
  else:
    ans+='*'
print(ans)
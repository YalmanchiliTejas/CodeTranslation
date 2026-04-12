n=int(input())
s=input()
k=int(input())
key=s[k-1]
ans=""
for i in range(len(s)):
  if s[i]==key:
    ans+=key
  else:
    ans+="*"
print(ans)

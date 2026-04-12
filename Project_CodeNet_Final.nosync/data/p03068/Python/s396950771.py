n=int(input())
s=input()
k=int(input())
ans=""
for i in range(len(s)):
  if s[i]==s[k-1]:
    ans+=s[i]
  else:
    ans+="*"
print(ans)
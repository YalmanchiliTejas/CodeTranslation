n=int(input())
s=input()
k=int(input())
hit=s[k-1]
ans=""
for let in s:
  if let != hit:
    ans+="*"
  else:
    ans+=hit
print(ans)
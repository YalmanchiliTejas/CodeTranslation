n = int(input())
s = input()
k = int(input())
ans,w = "",s[k-1]
for i in s:
  if i==w: ans+=w
  else: ans+="*"
print(ans)
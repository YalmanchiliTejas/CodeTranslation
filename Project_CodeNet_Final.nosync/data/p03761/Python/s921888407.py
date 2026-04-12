n=int(input())
ans="".join(sorted(input()))
for i in range(n-1):
  s=sorted(input())
  si=0
  ansi=0
  newans=""
  while si<len(s) and ansi<len(ans):
    if ans[ansi]==s[si]:
      newans+=ans[ansi]
      ansi+=1
      si+=1
    elif ans[ansi]>s[si]:
      si+=1
    else:
      ansi+=1
  ans=newans
print(ans)
N = int(input())
s = input()
dic = ['SS','SW','WS','WW']
for i in range(4):
  ans = dic[i]
  state = ans[-1]
  for j in range(1,N):
    if state=='S':
      if s[j]=='o':
        ans += ans[j-1]
      else:
        if ans[j-1]=='S':
          ans += 'W'
        else:
          ans += 'S'
    else:
      if s[j]=='o':
        if ans[j-1]=='S':
          ans += 'W'
        else:
          ans += 'S'
      else:
        ans += ans[j-1]
    state = ans[-1]
  if ans[0]==ans[-1]:
    ans = ans[:-1]
    if state=='S':
      if s[0]=='o':
        if ans[1]==ans[-1]:
          print(ans)
          break
      else:
        if ans[1]!=ans[-1]:
          print(ans)
          break
    else:
      if s[0]=='o':
        if ans[1]!=ans[-1]:
          print(ans)
          break
      else:
        if ans[1]==ans[-1]:
          print(ans)
          break
else:
  print(-1)
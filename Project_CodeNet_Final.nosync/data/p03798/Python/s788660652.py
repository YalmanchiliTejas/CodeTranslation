n=int(input())
s=list(input())
def func(a,b):
  ans=[a,b] #True:S, False:W
  for i in range(1,n):
    if s[i]=='o':
      if ans[-1]:
        ans.append(ans[-2])
      else:
        ans.append(not ans[-2])
    else:
      if ans[-1]:
        ans.append(not ans[-2])
      else:
        ans.append(ans[-2])
  if ans[0]==ans[-1]:
    flg=False
    if s[0]=='o' and a and ans[1]==ans[-2]:
      flg=True
    elif s[0]=='o' and not a and ans[1]!=ans[-2]:
      flg=True
    elif s[0]=='x' and a and ans[1]!=ans[-2]:
      flg=True
    elif s[0]=='x' and not a and ans[1]==ans[-2]:
      flg=True
    if flg:
      print(''.join(['S' if ansi else 'W' for ansi in ans[:-1]]))
      exit()
func(True,True)
func(True,False)
func(False,True)
func(False,False)
print(-1)

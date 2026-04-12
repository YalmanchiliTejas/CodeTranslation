n=int(input())
s=input()
def check(s1,s2):
  ans=[s1,s2]
  for i in range(1,n-1):
    if (ans[i]=='S' and s[i]=='o') or (ans[i]=='W' and s[i]=='x'):
      ans.append(ans[i-1])
    elif ans[i]=='S' and s[i]=='x' and ans[i-1]=='S':
      ans.append('W')
    elif ans[i]=='S' and s[i]=='x' and ans[i-1]=='W':
      ans.append('S')
    elif ans[i]=='W' and s[i]=='o' and ans[i-1]=='S':
      ans.append('W')
    elif ans[i]=='W' and s[i]=='o' and ans[i-1]=='W':
      ans.append('S')
  if ans[-1]=='S':
    if s[-1]=='o' and ans[0]==ans[-2]:
      if ans[0]=='S' and s[0]=='o' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='S' and s[0]=='x' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='o' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='x' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
    if s[-1]=='x' and ans[0]!=ans[-2]:
      if ans[0]=='S' and s[0]=='o' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='S' and s[0]=='x' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='o' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='x' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
  else:
    if s[-1]=='o' and ans[0]!=ans[-2]:
      if ans[0]=='S' and s[0]=='o' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='S' and s[0]=='x' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='o' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='x' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
    if s[-1]=='x' and ans[0]==ans[-2]:
      if ans[0]=='S' and s[0]=='o' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='S' and s[0]=='x' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='o' and ans[1]!=ans[-1]:
        print(''.join(ans))
        exit()
      if ans[0]=='W' and s[0]=='x' and ans[1]==ans[-1]:
        print(''.join(ans))
        exit()
  return
check('S','S')
check('S','W')
check('W','S')
check('W','W')
print(-1)
import sys
N=int(input())
s=str(input())
t=s.replace("o","2")
t=t.replace("x","0")
t=str(t)

ans="22"
for i in range(1,N):
  ans+=str( (int(t[i])-1) * (int(ans[i-1])-1)*(int(ans[i])-1)+1 )
if ans[0]==ans[N] and (int(ans[0])-1)*(int(t[0])-1)==(int(ans[1])-1)*(int(ans[N-1])-1):
  ans=ans.replace("2","S")
  ans=ans.replace("0","W")
  print(ans[0:N])
  sys.exit()

ans="20"
for i in range(1,N):
  ans+=str( (int(t[i])-1) * (int(ans[i-1])-1)*(int(ans[i])-1)+1 )
if ans[0]==ans[N] and (int(ans[0])-1)*(int(t[0])-1)==(int(ans[1])-1)*(int(ans[N-1])-1):
  ans=ans.replace("2","S")
  ans=ans.replace("0","W")
  print(ans[0:N])
  sys.exit()

ans="02"
for i in range(1,N):
  ans+=str( (int(t[i])-1) * (int(ans[i-1])-1)*(int(ans[i])-1)+1 )
if ans[0]==ans[N] and (int(ans[0])-1)*(int(t[0])-1)==(int(ans[1])-1)*(int(ans[N-1])-1):
  ans=ans.replace("2","S")
  ans=ans.replace("0","W")
  print(ans[0:N])
  sys.exit()

ans="00"
for i in range(1,N):
  ans+=str( (int(t[i])-1) * (int(ans[i-1])-1)*(int(ans[i])-1)+1 )
if ans[0]==ans[N] and (int(ans[0])-1)*(int(t[0])-1)==(int(ans[1])-1)*(int(ans[N-1])-1):
  ans=ans.replace("2","S")
  ans=ans.replace("0","W")
  print(ans[0:N])
  sys.exit()

print(-1)

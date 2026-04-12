n,s=map(int,input().split())
a=list(map(int,input().split()))
mod=998244353
dp00=[0]*(s+1)
dp01=[0]*(s+1)
dp10=[0]*(s+1)
dp11=[0]*(s+1)
dp20=[0]*(s+1)
dp21=[0]*(s+1)
dp00[0]=1
for i in range(n):
  for j in range(s+1):
    if i%2==0:
      if j>=a[i]:
        dp11[j]=(dp00[j-a[i]]+dp10[j-a[i]]+dp00[j]+dp10[j])%mod
        dp21[j]=(dp00[j-a[i]]+dp10[j-a[i]]+dp00[j]+dp10[j]+dp20[j])%mod
      else:
        dp01[j]=dp00[j]%mod
        dp11[j]=(dp00[j]+dp10[j])%mod
        dp21[j]=(dp00[j]+dp10[j]+dp20[j])%mod
    else:
      if j>=a[i]:
        dp10[j]=(dp01[j-a[i]]+dp11[j-a[i]]+dp01[j]+dp11[j])%mod
        dp20[j]=(dp01[j-a[i]]+dp11[j-a[i]]+dp01[j]+dp11[j]+dp21[j])%mod
      else:
        dp00[j]=dp01[j]%mod
        dp10[j]=(dp01[j]+dp11[j])%mod
        dp20[j]=(dp01[j]+dp11[j]+dp21[j])%mod
if n%2==1:
  print(dp21[s])
else:
  print(dp20[s])
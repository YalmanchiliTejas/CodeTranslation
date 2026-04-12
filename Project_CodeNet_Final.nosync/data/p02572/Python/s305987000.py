n=int(input())
a=list(map(int,input().split()))
mod=pow(10,9)+7
sa=[0]
tmp=0
for x in a:
  tmp+=x
  sa.append(tmp)
ans=0
for i in range(n-1):
  ans+=a[i]*(sa[n]-sa[i+1])
  ans%=mod
print(ans)
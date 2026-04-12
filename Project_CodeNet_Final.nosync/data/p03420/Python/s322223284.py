n,k=map(int,input().split())
ans=0
for i in range(k+1,n+1):#iは割る数
  num=i-k#k以上のあまりの種類
  c=n//i
  ans+=num*c#(c-1)~0まであまりがk~i-1
  r=n%i
  if r<k:
    pass
  else:
    ans+=r-k+1
if k==0:
  print(ans-n)
  exit()
print(ans)
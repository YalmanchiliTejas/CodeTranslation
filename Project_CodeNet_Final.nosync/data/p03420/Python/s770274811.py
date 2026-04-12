N,K=list(map(int,input().split()))
if K==0:
   print(N**2)
   exit()
ans=0
for i in range(1,N+1):#割る数
   if i<=K:
      continue
   else:
      ans+=(N//i)*(i-K)
      ans+=N-(N//i)*i-(K-1) if N-(N//i)*i-(K-1)>0 else 0
print(ans)
N=int(input())
a=[int(i) for i in input().split()]
ans=0
while True:
  f=0
  for i in range(N):
    if a[i]>=N:
      d=a[i]//N
      ans+=d
      a[i]%=N
      for j in range(N):
        if i!=j:
          a[j]+=d
    else:
      f+=1
  if f==N:
    break
print(ans)
      
  
        
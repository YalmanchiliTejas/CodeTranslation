n=int(input())
arr=list(map(int,input().split()))
cnt=0
while 1:
  tmp=[]
  flag=0
  for i in range(n):
    val=arr[i]
    if val<=n-1:
      flag+=1
    if (val+1)%(n+1):
      times=(val+1)//(n+1)
    else:
      times=(val+1)//(n+1)
    arr[i]-=times*n
    tmp.append(times)
  if flag==n:
    break
  sums=sum(tmp)
  cnt+=sums
  for i in range(n):
    arr[i]+=(sums-tmp[i])
print(cnt)
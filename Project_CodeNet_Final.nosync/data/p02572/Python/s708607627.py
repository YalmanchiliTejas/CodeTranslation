N=int(input())
Alist=list(map(int,input().split()))
sum1=0
sum2=0
for i in range(N):
  sum1=sum1+Alist[i]
  sum2=sum2+(Alist[i])**2
ans=(sum1**2-sum2)//2
print(ans%(10**9+7))
mod=10**9+7
n=int(input())
alist=list(map(int, input().split()))
suma=sum(alist)%mod
num=0
for i in range(n):
  num+=alist[i]**2
  num=num%mod
ans=(suma**2-num)%mod
if ans%2==0:
  print(ans//2)
else:
  print((ans+mod)//2)
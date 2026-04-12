m=1000000007
n=int(input())
l=list(map(int,input().split()))
ss=0
sum=[]
for i in l:
  ss=(ss+i)%m
  sum.append(ss)
s=0
for i in range(n):
  x=(l[i]*sum[n-1]-l[i]*sum[i])%m
  s=(s+x)%m
print(s)
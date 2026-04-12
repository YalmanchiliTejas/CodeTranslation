n=int(input())
a=list(map(int,input().split()))
am=sum(a)
sm=0

for i in range(len(a)):
  am-=a[i]
  sm=(sm+a[i]*am)%(10**9+7)
print(sm)
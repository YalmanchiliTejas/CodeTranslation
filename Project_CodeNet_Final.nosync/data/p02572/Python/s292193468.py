n=int(input())
a=list(map(int,input().split()))
suma=sum(a)
answer=0
for i in range(n):
  suma-=a[i]
  answer+=suma*a[i]
print(answer%(10**9+7))
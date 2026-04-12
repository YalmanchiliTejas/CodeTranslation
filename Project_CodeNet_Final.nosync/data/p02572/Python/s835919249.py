n = int(input())
a = list(map(int,input().split()))

tot = 0
sqr = 0
ind = 0
for i in range(n):
  tot += a[i]

sqr = tot*tot
for i in range(n):
  ind += a[i]*a[i]

print(((sqr-ind)//2)%1000000007)
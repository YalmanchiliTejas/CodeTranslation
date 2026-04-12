n=int(input())
sums=0
a=list(map(int, input().split()))
b = sum(a)
for i in range(n):
  b -= a[i]
  sums += a[i]*b
  sums = sums%((10**9)+7)
print(sums)

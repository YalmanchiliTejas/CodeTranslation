n = int(input())

a = list(map(int, input().split()))

sigma = 0
after = sum(a[0:])
for i in range(len(a)-1):
  start = a[i]
  after = after - a[i]
  sigma = sigma + start * after
  if sigma >= (10**9 + 7):
    sigma = sigma % (10**9+7)

print(sigma)

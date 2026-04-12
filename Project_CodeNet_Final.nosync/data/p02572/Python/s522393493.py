n = int(input())

a = list(map(int, input().split()))

sigma = sum(a)
count = 0
for i in range(len(a)-1):
  start = a[i]
  sigma = sigma-a[i]
  count = count + start * sigma
  if count >= 10**9+7:
    count = count % (10**9+7)

print(count)
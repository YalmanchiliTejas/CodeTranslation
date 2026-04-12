a = int(input())
b = list(map(int, input().split()))
c = 0
sum = sum(b)
for i in range(a-1):
  sum = sum - b[i]
  c += b[i]*(sum)
print(c%(10**9+7))
n = int(input())
a = list(map(int, input().split()))
left = 0
right = 0
for i in range(n):
  left += a[i]
  left %= (10**9+7)
for j in range(n):
  right += a[j]
  right %= (10**9+7)
c = (left*right)%(10**9+7)
l = [(k**2)%(10**9+7) for k in a]
print(((c+(10**9+7)-sum(l)%(10**9+7))*pow(2, 10**9+5, 10**9+7))%(10**9+7))
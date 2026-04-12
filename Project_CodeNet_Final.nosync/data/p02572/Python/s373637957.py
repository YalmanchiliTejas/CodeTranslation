n = int(input())
a = list(map(int, input().split()))
b = 0; c = 0
for i in range(n): b += a[i]; c += a[i]**2
print((b**2-c)//2%(10**9+7))
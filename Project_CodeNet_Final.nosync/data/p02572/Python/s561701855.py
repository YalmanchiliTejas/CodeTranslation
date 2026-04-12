n = int(input())
a = list(map(int, input().split()))
p = 1000000007
 
y = 0
for i in range(n):
    y += a[i]
    y = y % (2 * p)
y = (y ** 2) % (2 * p)
 
x = 0
for j in range(n):
    x += a[j] ** 2
    x = x % (2 * p)
 
z = int(((y - x) / 2) % p)
print(z)
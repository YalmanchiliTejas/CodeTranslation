n = int(input())
a = list(map(int, input().split()))
p = 1000000007
 
z = 0
for i in range(n):
    z += a[i]
    z = z % (2 * p)
z = (z ** 2) % (2 * p)
 
x = 0
for j in range(n):
    x += a[j] ** 2
    x = x % (2 * p)
 
w = int(((z - x) / 2) % p)
print(w)
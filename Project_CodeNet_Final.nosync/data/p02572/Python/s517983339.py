n = int(input())
a = list(map(int, input().split()))
x = 0
y = 0
for i in range(0,n):
    x = x + a[i]
for i in range(0,n):
    y = y + (a[i]**2)
print(((x**2-y)//2) % (10**9+7))
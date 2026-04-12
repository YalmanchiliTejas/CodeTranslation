n = int(input())
a = list(map(int, input().split()))
x = 0
m = sum(a)
for i in range(len(a)-1):
    m = (m-a[i])%(10**9+7)
    x += a[i]*m
    x = x%(10**9+7)
print(x%(10**9+7))
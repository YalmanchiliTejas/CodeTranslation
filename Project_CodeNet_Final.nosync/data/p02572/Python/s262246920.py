n = int(input())
a = list(map(int, input().split()))
k = 0
num = sum(a)

for i in range(n):
    k = k + (a[i] * num) - (a[i] ** 2)

x = k // 2
t = 10 ** 9 + 7
ans = x % t
print(ans)

n = int(input())
a = list(map(int, input().split()))
b = sum(a)
ans = 0

for i in range(0, n):
    b = b - a[i]
    ans = ans + a[i] * b
    ans = ans % 1000000007

print(ans)

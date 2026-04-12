n = int(input())
a = list(map(int, input().split()))
b = sum(a)
ans = 0
for i in range(n-1):
    ans += a[i] *(b-a[i])
    b = b - a[i]
print(ans % (10**9 + 7))
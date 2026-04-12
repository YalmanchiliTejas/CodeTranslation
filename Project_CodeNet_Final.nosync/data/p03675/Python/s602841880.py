n = int(input())
a = list(map(str, input().split()))
ans = ""
if n % 2 == 0:
    for i in range(n-1, -1, -2):
        ans += a[i] + " "
    for i in range(0, n, 2):
        ans += a[i] + " "
else:
    for i in range(n-1, -1, -2):
        ans += a[i] + " "
    for i in range(1, n, 2):
        ans += a[i] + " "
print(ans)

n = int(input())
a = list(map(int, input().split()))
ans = 0
while max(a) >= n:
    count = 0
    for i in range(n):
        count += a[i]//n
        a[i] = a[i]%n - a[i]//n
    for i in range(n):
        a[i] += count
    ans += count
print(ans)

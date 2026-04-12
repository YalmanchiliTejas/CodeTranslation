n = int(input())
a = list(map(int, input().split()))
a = [i % (10**9 + 7) for i in a]
val = sum(a[1:])
l = [val]
for i in range(1, n):
    val -= a[i]
    l.append(val)
ans = 0
for i in range(n - 1):
    ans += a[i]*l[i]
    ans %= 10**9 + 7
print(ans)
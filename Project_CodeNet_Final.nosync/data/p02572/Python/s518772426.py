n = int(input())
a = list(map(int, input().split()))
p = 10**9 + 7

acmlator = sum(a[1:]) % p
ans = (a[0] * acmlator) % p
if n == 2:
    print(ans)
else:
    for i in range(1, n - 1):
        acmlator = (acmlator - a[i]) % p
        ans = (ans + a[i] * acmlator) % p
    print(ans)

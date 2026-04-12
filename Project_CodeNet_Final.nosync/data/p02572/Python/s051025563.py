n = int(input())
numbers = [int(x) for x in input().split()]
r = 10**9 + 7

cum = [0] * n
cum[0] = numbers[0]
for i in range(1, n):
    cum[i] += cum[i - 1] + numbers[i]
    cum[i] %= r
   
ans = 0
for i in range(n - 1):
    tmp = numbers[i] * (cum[n - 1] - cum[i])
    tmp %= r
    ans += tmp
    ans %= r

print(ans)
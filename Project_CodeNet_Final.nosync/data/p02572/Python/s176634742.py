N = int(input())

A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

tmp = 0

ans = 0

for num in A:
    ans += tmp * num % MOD
    tmp += num
print(ans%MOD)
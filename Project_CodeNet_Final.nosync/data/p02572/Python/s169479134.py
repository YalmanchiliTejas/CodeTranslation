n = int(input())
a_array = map(int, input().split())
MOD = 10 ** 9 + 7
a_array = [a % MOD for a in a_array]
sum = 0
square_sum = 0
for i in range(n):
    sum += a_array[i]
    sum %= MOD
    square_sum += pow(a_array[i], 2, MOD)
    square_sum %= MOD

ans = pow(sum, 2, MOD) - square_sum
ans *= 500000004
ans %= MOD
print(ans)

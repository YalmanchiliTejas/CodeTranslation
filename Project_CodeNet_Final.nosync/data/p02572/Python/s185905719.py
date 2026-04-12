N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7

arr_sum = 0
for i in range(N):
    arr_sum = (arr_sum + A[i]) % mod

arr_sum_square = (arr_sum * arr_sum) % mod

individual_square_sum = 0
for i in range(N):
    individual_square_sum = (individual_square_sum + (A[i] * A[i]) % mod) % mod

ans = arr_sum_square - individual_square_sum
ans = ans * pow(2, mod - 2, mod)
ans %= mod
print(ans)

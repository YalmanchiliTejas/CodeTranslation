_ = input()
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

sum_A = sum(A)
a_a = [(a * a) for a in A]

ans = ((sum_A ** 2)- sum(a_a)) // 2

print(ans % MOD)
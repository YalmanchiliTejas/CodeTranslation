# https://atcoder.jp/contests/arc091/tasks/arc091_b

n, k = map(int, input().split())
ans = 0
for i in range(1, n + 1):
    surplus = n // i
    quotient = n % i
    ans += surplus * max(0, i - k) + max(0, quotient - k + 1)
print(ans if k != 0 else ans - n)

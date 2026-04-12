N = int(input())
A = list(map(int, input().split()))

ans = 0
mod = 10 ** 9 + 7
num = sum(A)

for a in A:
    num -= a
    ans += a * num

print(ans % mod)
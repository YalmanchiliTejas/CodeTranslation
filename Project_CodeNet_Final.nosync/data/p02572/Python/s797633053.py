def mod(num):
    return num % (10 ** 9 + 7)


N = int(input())
A = list(map(int, input().split()))

Asum = sum(A)

ans = 0

for i, a in enumerate(A):
    Asum -= a
    ans = mod(ans + Asum * a)

print(ans)
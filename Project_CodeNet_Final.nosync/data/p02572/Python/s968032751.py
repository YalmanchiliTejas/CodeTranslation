N = int(input())
As = list(map(int, input().split()))

Asum = sum(As)

ans = 0
for index, A in enumerate(As):
    ans += (A * (Asum - A))
    ans = ans % (10**9+7)
    Asum -= A
#    print(
#    print(As)

print(ans)
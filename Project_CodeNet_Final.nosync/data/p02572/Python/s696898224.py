n = int(input())
a = list(map(int, input().split()))
asum = sum(a)
ans = 0
mm = 1000000007
for i in a:
    asum -= i
    ll = i * (asum)
    ll = ll % mm
    ans += ll
    ans = ans % mm

print(ans)
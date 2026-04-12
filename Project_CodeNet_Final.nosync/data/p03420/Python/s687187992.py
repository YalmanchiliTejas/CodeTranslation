n, k = map(int, input().split())

ans = 0
if k == 0:
    print(n * n)
    exit()

for i in range(k + 1, n + 1):
    # 周期i
    # 0 1 2 3 ... i - 1, 0,
    # 1周期にi - kこk以上

    # 1始まりなのがめんどい
    # 最初1周期だけさせる
    m = n
    m -= i - 1
    ans += i - k

    full = m // i * (i - k)
    amari = m % i  # 周期の途中でnを超える
    ans += full + max(0, amari - k)
print(ans)

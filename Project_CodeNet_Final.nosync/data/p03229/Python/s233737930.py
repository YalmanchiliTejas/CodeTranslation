n = int(input())
a = [int(input()) for _ in range(n)]

a = sorted(a)
l = len(a)

if n % 2 == 0:
    # 谷max, 山, 谷, ..., 山, 谷, 山min
    tani = sorted(a[:l // 2], reverse=True)
    yama =  a[l // 2 + 1:] + [a[l // 2]]
    ans = 0
    for i in range(l //2):
        ans += yama[i] - tani[i]
    for i in range(l //2 - 1):
        ans += yama[i] - tani[i + 1]
    print(ans)

else:
    # 谷max, 山, 谷, ..., 山, 谷max
    tani = sorted(a[:l // 2 + 1], reverse=True)
    tani = tani[1:] + [tani[0]]
    yama = a[l // 2 + 1:]
    t = 0
    for i in range(l // 2):
        t += yama[i] - tani[i]
    for i in range(l // 2):
        t += yama[i] - tani[i + 1]
    ans = t

    # 山min, 谷, 山, ..., 谷, 山min
    tani = sorted(a[:l // 2], reverse=True)
    yama = a[l // 2:]
    yama = yama[1:] + [yama[0]]
    t = 0
    for i in range(l // 2):
        t += yama[i] - tani[i]
    for i in range(l // 2):
        t += yama[i + 1] - tani[i]

    ans = max(ans, t)
    print(ans)
N = int(input())
s = list(map(int, input().split(" ")))

ans = 0
for q in range(1, N - 1):
    k = 0
    a1 = 0
    seen = set()

    p = N - 1 - k * q
    while p > q:
        if k * q in seen:
            break
        seen.add(k * q)
        if p in seen:
            break
        seen.add(p)

        a1 = a1 + s[p] + s[k * q]
        # print(p, p - q,  a1)
        ans = max(ans, a1)

        k += 1
        p = N - 1 - k * q

print(ans)

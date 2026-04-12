def reverse_insort(a, x):
    lo = 0
    hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if x > a[mid]:
            hi = mid
        else:
            lo = mid + 1
    return lo


n = int(input())

ans = []
ans.append(int(input()))

for i in range(n - 1):
    t = int(input())
    ch = 0
    if t <= ans[-1]:
        ans.append(t)
    else:
        ans[reverse_insort(ans, t)] = t

print(len(ans))

import bisect
def bisect_rev(a, x):
    lo = 0
    hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if x > a[mid]:
            hi = mid
        else:
            lo = mid + 1
    return lo

def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    t = []
    for a in A:
        k = bisect_rev(t, a)
        if k == len(t):
            t.append(a)
        else:
            t[k] = a
    return len(t)

print(main())

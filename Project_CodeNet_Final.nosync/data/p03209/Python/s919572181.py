def bottom(lv, k):
    if lv == 0:
        return 1
    n = 2**(lv+2) - 3
    prev_pat = 2**lv-1
    if k-1 == 0:
        return 0
    elif 0 < k-1 < n//2:
        return bottom(lv-1, k-1)
    elif k-1 == n//2:
        return prev_pat + 1
    elif n//2 < k-1 < n-1:
        return prev_pat + 1 + bottom(lv-1, k-(n//2+1))
    elif k-1 == n-1:
        return 2**(lv+1)-1

n, k = list(map(int, input().split()))

print(bottom(n, k))

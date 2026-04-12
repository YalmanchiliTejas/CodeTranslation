def bisect_right_descending(a, x, lo=0, hi=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if x > a[mid]: hi = mid
        else: lo = mid+1
    return lo


n = int(input())

b = []

for i in range(n):
    a = int(input())
    c = bisect_right_descending(b,a)
    if c==len(b):
        b.append(a)
    else:
        b[c]=a

print(len(b))
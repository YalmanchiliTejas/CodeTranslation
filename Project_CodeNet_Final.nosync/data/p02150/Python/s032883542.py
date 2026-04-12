A, B, X = map(int, raw_input().split())

def check(n):
    if n == 0:
        return True
    v = X - n * A + n * B
    return v - B >= 0

hi = 10**16
lo = 0

while hi - lo > 1:
    mid = (hi + lo) / 2
    if check(mid):
        lo = mid
    else:
        hi = mid

print (X + lo * B) % (10 ** 9 + 7)


def fn(k):
    return pow(2, k + 2) - 3

def pn(n, x):
    rec = 0
    if n == 0:
        if x >= 1:
            return 1
        return 0

    sum_f = fn(n - 1)
    if x <= sum_f + 1:
        rec += pn(n - 1, x - 1)

    elif x == sum_f + 2:
        rec += pow(2, n)

    else:
        rec += pow(2, n) + pn(n - 1, x - (sum_f + 2))

    return rec

n, x = map(int,input().split())
rec = pn(n, x)
print(rec)

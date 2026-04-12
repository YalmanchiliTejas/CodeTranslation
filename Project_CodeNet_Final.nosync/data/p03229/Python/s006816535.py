n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

a = sorted(a)

if n == 2:
    print(a[1] - a[0])
    exit()

res1 = a[n - 1] + a[n - 2] - (a[0] * 2)
p = n - 3
q = 1
mode = 0
while 1:
    #print(p, q, res1)
    if p < q:
        break
    elif p == q:
        if mode == 0:
            res1 += a[p + 2] - a[p]
        else:
            res1 += a[p] - a[p - 2]
        break
    else:
        if mode == 0:
            res1 += a[p + 1] + a[p + 2] - a[q] - a[q + 1]
            mode = 1
            q += 2
        else:
            res1 += a[p] + a[p - 1] - a[q - 1] - a[q - 2]
            mode = 0
            p -= 2

res2 = a[n - 1] * 2 - a[0] - a[1]
p = n - 2
q = 2
mode = 1
while 1:
    #print(p, q, res2)
    if p < q:
        break
    elif p == q:
        if mode == 0:
            res2 += a[p + 2] - a[p]
        else:
            res2 += a[p] - a[p - 2]
        break
    else:
        if mode == 0:
            res2 += a[p + 1] + a[p + 2] - a[q] - a[q + 1]
            mode = 1
            q += 2
        else:
            res2 += a[p] + a[p - 1] - a[q - 1] - a[q - 2]
            mode = 0
            p -= 2

print(max(res1, res2))
n = int(input())
a = [int(input()) for _ in range(n)]
b = [-1]
c = 1


def bi(a, x):
    i, j = 0, len(a) - 1
    while i != j:
        k = (i + j) // 2
        if a[k] >= x:
            i = k+1
        else:
            j = k
    if a[-1] >= x:
        i =-1
    return i


for i in a:
    j = bi(b, i)
    if j == -1:
        b.append(i)
        c += 1
    else:
        b[j] = i
print(c)

n, x = map(int, input().split())

A = [1] * (n + 1)
P = [1] * (n + 1)
for i in range(1, n + 1):
    A[i] = A[i - 1] * 2 + 3
    P[i] = P[i - 1] * 2 + 1


def pate(m, y):
    if m == 0:
        return 1
    else:
        c = 0

        if y >= 1:
            y -= 1

        if y >= 1:
            if y >= A[m - 1]:
                y -= A[m - 1]
                c += P[m - 1]
            else:
                c += pate(m - 1, y)
                y = 0

        if y >= 1:
            y -= 1
            c += 1

        if y >= 1:
            if y >= A[m - 1]:
                y -= A[m - 1]
                c += P[m - 1]
            else:
                c += pate(m - 1, y)
                y = 0

        if y >= 1:
            y -= 1

        return c


print(pate(n, x))

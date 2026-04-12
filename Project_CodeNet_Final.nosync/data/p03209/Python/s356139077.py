n, x = map(int, input().split())

A = [1] * (n + 1)
P = [1] * (n + 1)
for i in range(1, n + 1):
    A[i] = A[i - 1] * 2 + 3
    P[i] = P[i - 1] * 2 + 1

c = 0
for i in list(range(n+1))[::-1]:
    if i == 0:
        c += 1

    elif x == 1:
        break

    elif x <= A[i - 1] + 1:
        x -= 1

    elif x == A[i - 1] + 2:
        c += P[i - 1] + 1
        break

    elif x <= A[i] - 1:
        c += P[i - 1] + 1
        x -= A[i - 1] + 2

    elif x == A[i]:
        c += P[i]
        break

print(c)

N, X = map(int, input().split())

counts = [0] * (N+1)
counts[0] = 1
for i in range(1, N+1):
    counts[i] = 2 * counts[i-1] + 3


def req(n, x):
    if n == 0:
        return 1

    if x == 1:
        return 0
    elif x > 1 and x <= counts[n-1] + 1:
        return req(n - 1, x - 1)
    elif x == counts[n-1] + 2:
        return req(n - 1, counts[n-1]) + 1
    else:
        if x == 2*counts[n-1] + 3:
            return req(n-1, counts[n-1]) * 2 + 1
        else:
            return req(n-1, x - (counts[n-1] + 2)) + req(n - 1, counts[n-1]) + 1


print(req(N, X))

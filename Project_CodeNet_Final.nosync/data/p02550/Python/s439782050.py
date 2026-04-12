N, X, M = map(int, input().split())
flag = [False for _ in range(M)]
record = list()
record.append(X)
flag[X] = 1

An = X

for i in range(M + 1):
    An = pow(An, 2, M)
    if flag[An]:
        start = flag[An]
        cnt = i + 2 - start
        cost = record[-1] - record[start - 2] if start > 1 else record[-1]
        break

    else:
        record.append(An + record[-1])
        flag[An] = i + 2

if start >= N:
    print(record[N - 1])
else:
    print(((N - start) // cnt) * cost
                + record[(N - start) % cnt + start - 1])

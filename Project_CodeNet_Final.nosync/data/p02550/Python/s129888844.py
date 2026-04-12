N, X, M = map(int, input().split())

candicate = [pow(i, 2, M) for i in range(M)]
ans = 0
now = X
A = [0]
X2 = pow(X, 2, M)

d = dict()

flag = True
for i in range(1, N+1):
    if i == 1:
        A.append(X)
    
    else:
        nxt = candicate[A[i-1]]

        if d.get(nxt) == None:
            if nxt == 0:
                A.append(nxt)
                break
            else:
                A.append(nxt)
                d[nxt] = i

        else:
            flag = False
            break


if flag:
    print(sum(A))
else:
    l = d[nxt]
    r = i - 1
    circle_total = 0
    for j in range(l, r+1):
        circle_total += A[j]
    
    for j in range(1, l):
        ans += A[j]

    width = r - l + 1
    N -= (l - 1)
    ans += circle_total * (N // width)

    for j in range(l, l + N % width):
        ans += A[j]

    print(ans)

def n():
    A, B, C, X, Y = map(int, input().split())
    ab = A + B
    cc = C * 2
    cost = 0
    if ab > cc:
        minn = min(X, Y)
        cost += minn * cc
    else:
        minn = min(X, Y)
        cost += minn * A + minn * B

    if X > Y:
        diff = X - Y
        aaa = A * diff
        ccc = cc * diff
        cost += min(aaa, ccc)
    else:
        diff = Y - X
        bbb = B * diff
        ccc = cc * diff
        cost += min(bbb,ccc)

    return cost


print(n())

X, Y, Z = list(map(int, input().split()))
W = X - Z*2
if W < Y:
    print(0)
else:
    W -= Y
    ans = 1

    ans += W // (Y+Z)
    print(ans)

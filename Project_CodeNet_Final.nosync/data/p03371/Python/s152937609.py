def c_half_and_half(A, B, C, X, Y):
    if X <= Y:
        tmp = X * 2 * C + (Y - X) * B
    else:
        tmp = Y * 2 * C + (X - Y) * A
    ans = min(tmp, max(X, Y) * 2 * C, X * A + Y * B)
    return ans

A,B,C,X,Y = [int(i) for i in input().split()]
print(c_half_and_half(A, B, C, X, Y))
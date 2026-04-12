A, B, C, X, Y = map(int, input().split())

if A + B < 2 * C:
    print(A*X + B*Y)

else:
    ans = 2*C*max(X, Y)

    C_num = min(X, Y)
    if X > Y:
        print(min(ans, C_num*2*C + A*(X-C_num)))
    else:
        print(min(ans, C_num*2*C + B*(Y-C_num)))

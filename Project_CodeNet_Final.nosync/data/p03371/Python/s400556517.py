A, B, C, X, Y = map(int, input().split())

if A + B < 2 * C:
    print(A*X + B*Y)

else:
    C_num = min(X, Y)
    print(min(2*C*max(X, Y), C_num*2*C + A*(X-C_num) + B*(Y-C_num)))
A, B, C, X, Y = map(int, input().split())
ans = A*X+B*Y
C = 2 * C

for i in range(1, max(X,Y)+1):
    if X >= i:
        A_num = X-i
    else:
        A_num = 0
    if Y >= i:
        B_num = Y-i
    else:
        B_num = 0
    # print(i, C*i+A*A_num+B*B_num, A_num, B_num)
    ans = min(ans, C*i+A*A_num+B*B_num)

print(ans)

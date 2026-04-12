A, B, C, X, Y = map(int, input().split())

ans = 1000000007
for i in range(max(X, Y) + 1):
    i_C = 2 * i
    i_A = max(0, X - i)
    i_B = max(0, Y - i)
    #
    ans = min(ans, A * i_A + B * i_B + C * i_C)

print(ans)

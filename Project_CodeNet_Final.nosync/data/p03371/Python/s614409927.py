A, B, C, X, Y = map(int, input().split())

ans = 10**9
for i in range(max(X, Y)+1):
    price = 2*C*i
    p_A, p_B = X, Y
    p_A -= i
    p_B -= i
    if p_A > 0:
        price += p_A*A
    if p_B > 0:
        price += p_B*B
    ans = min(ans, price)

print(ans)

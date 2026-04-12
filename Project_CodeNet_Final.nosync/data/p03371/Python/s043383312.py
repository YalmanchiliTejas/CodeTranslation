A, B, C, X, Y = map(int, input().split())

# AB購入数が決まるとA購入数とB購入数が決まるので、それを利用して総当りする

cost = set()
for n_AB in range(0, max(X,Y)*2 + 1, 2):
    n_A = max(0, X - n_AB//2)
    n_B = max(0, Y - n_AB//2)
    cost.add(n_A*A + n_B*B + n_AB*C)

print(min(cost))
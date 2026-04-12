A, B, C, X, Y = map(int, input().split())

r = []

# Cピザを使わない
t1 = A * X + B * Y
r.append(t1)

# Cピザをmin(A*2, B*2)まで買う
x = min(X, Y)
ab = 2 * x
t2 = ab * C + (X - x) * A + (Y - x) * B
r.append(t2)

# Cピザで賄う
x = max(X, Y)
ab = 2 * x
t3 = ab * C
r.append(t3)

print(min(r))
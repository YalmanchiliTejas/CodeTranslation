A, B, AB, X, Y = map(int, input().split())

A_p = A * X
B_p = B * Y
justAB = A_p + B_p

min_x_y = min(X, Y)
AB_p = int((min_x_y / 0.5 * AB))

dif = 0
dif_p = 0
if X > Y:
    dif = X - Y
    dif_p = dif * A
else:
    dif = Y - X
    dif_p = dif * B


max_x_y = max(X,Y)
AB_max_p = int(max_x_y / 0.5 * AB)

print(min(justAB, AB_p + dif_p, AB_max_p))

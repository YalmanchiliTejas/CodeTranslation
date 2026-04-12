A, B, C, X, Y = map(int, input().split())


min_cost = 0

if X - Y > 0:
    temp_cost = 2 * C * Y
    temp_cost += A * (X - Y)    

    temp_cost2 = 2 * C * X

    if temp_cost > temp_cost2:
        min_cost = temp_cost2
    else:
        min_cost = temp_cost

else:
    temp_cost = 2 * C * X
    temp_cost += B * (Y - X)

    temp_cost2 = 2 * C * Y

    if temp_cost > temp_cost2:
        min_cost = temp_cost2
    else:
        min_cost = temp_cost


temp_cost3 = A * X + B *Y

if temp_cost3 < min_cost:
    min_cost = temp_cost3

print(min_cost)


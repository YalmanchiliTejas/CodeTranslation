A, B, C, X, Y = [int(i) for i in input().split()]

if X > Y:
    max_pizzas = X
else :
    max_pizzas = Y
    
costs = []
for i in range(max_pizzas+1):
    A_left = X - i
    B_left = Y - i
    if A_left > 0:
        A_cost = A * A_left
    else :
        A_cost = 0

    if B_left > 0:
        B_cost = B * B_left
    else :
        B_cost = 0
    
    costs.append(A_cost + B_cost + (C * 2 * i))
    
print(min(costs))
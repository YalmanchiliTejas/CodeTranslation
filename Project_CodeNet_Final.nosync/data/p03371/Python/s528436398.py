A, B, C, X, Y = input().split(" ")
A, B, C, X, Y  = int(A), int(B), int(C), int(X), int(Y)

cost_AplusB = min(A+B, 2*C)
costA = min(A, 2*C)
costB = min(B, 2*C)

flag = (X > Y)
many_pizza = max(X, Y)
few_pizza = min(X, Y)



price = cost_AplusB * few_pizza
if flag:
    price += costA * (many_pizza - few_pizza)
else:
    price += costB  * (many_pizza - few_pizza)

print(price)


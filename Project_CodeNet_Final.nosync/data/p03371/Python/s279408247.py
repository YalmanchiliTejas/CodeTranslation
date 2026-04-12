A,B,C,X,Y = map(int,input().split())
achete_A = 0
achete_B = 0
price = 0
C = 2 * C #=A,B
while achete_A < X and achete_B < Y:
    if A+B <= C:
        achete_A += 1
        achete_B += 1
        price += (A+B)
    else:
        achete_A += 1
        achete_B += 1
        price += C
if achete_A < X :
    while achete_A < X:
        if A < C:
            achete_A += 1
            price += A
        else:
            achete_A += 1
            price += C
elif achete_B < Y:
    while achete_B < Y:
        if B < C:
            achete_B += 1
            price += B
        else:
            achete_B += 1
            price += C
print(price)
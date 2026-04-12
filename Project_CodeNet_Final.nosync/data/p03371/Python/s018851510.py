A,B,C,X,Y = (int(i) for i in input().split())


# ABピザをZ枚買ったとする
mcost = 2 ** 30
for i in range(0,200001,2):
    XX = max(0, X - (i // 2))
    YY = max(0,Y - (i // 2))
    cost = XX * A + YY * B + i * C
    if mcost > cost:
        mcost = cost

print(mcost)

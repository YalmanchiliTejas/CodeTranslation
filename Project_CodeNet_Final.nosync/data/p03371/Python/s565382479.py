A, B, C, X, Y = [int(i) for i in input().split()]

cost1 = X * A + Y * B

c = X * 2
a = 0
b = max([0, Y - c / 2])
cost2 = a * A + b * B + c * C

c = Y * 2
a = max([0, X - c / 2])
b = 0
cost3 = a * A + b * B + c * C

print(int(min([cost1, cost2, cost3])))


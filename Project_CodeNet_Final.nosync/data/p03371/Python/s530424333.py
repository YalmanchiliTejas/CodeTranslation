# C
a, b, c, x, y = map(int, input().split())

# A and B
AandB = a*x + b*y
# AB and A or B
if x > y:
    ABandAorB = 2*c*y + a * (x-y)
else:
    ABandAorB = 2*c*x + b * (y-x)
# only AB
if x > y:
    AB = 2*c*x
else:
    AB = 2*c*y
print(min(AandB,ABandAorB,AB))
p = [int(x) for x in input().split()]

A = p[0]
B = p[1]
C = p[2]
X = p[3]
Y = p[4]

total = 0

if A + B > 2 * C:
    while X and Y > 0:
        total += 2 * C
        X -= 1
        Y -= 1      

while X > 0:
    if A > 2 * C:
        total += 2 * C
    else:
        total += A
    X -= 1
while Y > 0:
    if B > 2 * C:
        total += 2 * C
    else:
        total += B
    Y -= 1

print(total)
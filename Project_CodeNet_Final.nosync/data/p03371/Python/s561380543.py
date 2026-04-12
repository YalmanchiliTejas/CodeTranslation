A, B, C, X, Y = map(int, input().split())
sum = 0

while X > 0 or Y > 0:
    if X > 0 and Y > 0:
        if A + B > 2 * C:
            sum += 2 * C
        else:
            sum += A + B
        X -= 1
        Y -= 1
    else:
        if X > 0:
            if A > 2 * C:
                sum += 2 * C
            else:
                sum += A
            X -= 1
        else:
            if B > 2 * C:
                sum += 2 * C
            else:
                sum += B
            Y -= 1

print(sum)

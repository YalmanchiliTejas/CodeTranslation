A, B, C, X, Y = map(int, input().split())
temp = A * X + B * Y
while True:
    if min(X, Y) > 0:        
        X -= 1
        Y -= 1
        now = temp - A - B + 2 * C
        if min(temp, now) == temp:
            break
        else:
            temp = now
    elif max(X, Y) > 0:
        if X == 0:
            Y -= 1
            now = temp - B + 2 * C
            if min(temp, now) == temp:
                break
            else:
                temp = now
        else:
            X -= 1
            now = temp - A + 2 * C
            if min(temp, now) == temp:
                break
            else:
                temp = now
    else:
        break
print(temp)
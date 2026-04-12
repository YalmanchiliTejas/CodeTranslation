A, B, C, X, Y = map(int, input().split(' '))

if C * 2 <= A and C * 2 <= B:
    print(max(X, Y) * 2 * C)
    exit()

if C * 2 >= A + B:
    print(A * X + B * Y)
    exit()

result = 0
while True:
    if X <= 0 and Y <= 0:
        break

    if X == 0 and C * 2 >= B:
        print(result + Y * B)
        exit()
    elif Y == 0 and C * 2 >= A:
        print(result + X * A)
        exit()

    result += C * 2
    X -= 1
    Y -= 1

print(result)
A, B, C, X, Y = map(int, input().split())

answer = 10 ** 18
for c in range(10 ** 5 + 1):
    a = X - c
    b = Y - c
    cost = C * c * 2
    cost += max(a, 0) * A
    cost += max(b, 0) * B
    if answer > cost:
        answer = cost
print(answer)
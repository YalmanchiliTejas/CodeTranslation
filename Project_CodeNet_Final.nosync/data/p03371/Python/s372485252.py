ABCXY = [int(i) for i in input().split()]
A, B, C, X, Y = ABCXY[0], ABCXY[1], ABCXY[2], ABCXY[3], ABCXY[4]
ans = 0

if 2 * C <= A + B:
    min_pizza = min(X, Y)
    ans += min_pizza * 2 * C
    X -= min_pizza
    Y -= min_pizza

if 2 * C <= A:
    ans += X * 2 * C
else:
    ans += X * A

if 2 * C <= B:
    ans += Y * 2 * C
else:
    ans += Y * B

print(ans)
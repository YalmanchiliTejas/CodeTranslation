A, B, C, X, Y = map(int, input().split())
faceAB = (A + B) / 2
sumPizza = 0

if faceAB <= C:
    ans = X * A + Y * B
else:
    def2 = 2 * C * max(X, Y)
    if X <= Y:
        tmp = 2 * C * min(X, Y) + ((Y - X) * B)
    else:
        tmp = 2 * C * min(X, Y) + ((X - Y) * A)
    ans = min(def2, tmp)
print(ans)

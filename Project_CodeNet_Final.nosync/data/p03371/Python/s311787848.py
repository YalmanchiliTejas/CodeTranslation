A, B, C, X, Y = map(int, input().split())

ans = 10 ** 18
for i in range(max(X, Y) + 1): #ABピザを2 * i枚買う
    tmp = 2 * i * C
    x = max(0, X - i)
    y = max(0, Y - i)
    tmp += x * A + y * B
    ans = min(ans, tmp)

print (ans)
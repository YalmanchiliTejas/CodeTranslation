A, B, C, X, Y = map(int, input().split())

# ABピザ以外で考えると
ans = A * X + B * Y

# ABピザを全探索して考える
for i in range(2, max(2*X,2*Y)+1, 2):
    x = X - i // 2
    y = Y - i // 2
    ans = min(ans, A * max(0,x) + B * max(0,y) + C * i)

print(ans)

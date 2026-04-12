A, B, C, X, Y = map(int, input().split())

ans = []

for z in range(0,max(X+1, Y+1)*2, 2):
    x = max(X - z//2, 0)
    y = max(Y - z//2, 0)
    ans.append((A * x) + (B * y) + (C * z))

print(min(ans))

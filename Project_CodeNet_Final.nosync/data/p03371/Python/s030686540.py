A, B, C, X, Y = map(int, input().split())
pair = min(A + B, 2 * C) 
ans = 0
remained_X = X!=0
remained_Y = Y!=0

while X != 0 and Y != 0:
    ans += pair
    X -= 1
    Y -= 1

price_A = min(A, 2 * C)
price_B = min(B, 2 * C)
ans += price_A * X + price_B * Y

print(ans)
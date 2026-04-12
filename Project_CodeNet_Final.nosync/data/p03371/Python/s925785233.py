
a, b, c, x, y = [ int(v) for v in input().split() ]
ans = 10**10
for i in range(max(x,y)*2+2):
    x_i, y_i = x - i // 2, y - i // 2
    if x_i < 0:
        x_i = 0
    if y_i < 0:
        y_i = 0
    total = x_i * a + y_i * b + c * i
    ans = min(ans,total)

print(ans)


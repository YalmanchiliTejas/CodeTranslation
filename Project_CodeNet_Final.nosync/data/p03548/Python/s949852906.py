x, y, z = map(int, input().split())
ans = 1

for i in range(x // y):
    ans += 1
    if y * ans + z * (ans + 1) > x:
        print(ans - 1)
        exit()
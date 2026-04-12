X, Y, Z = map(int, input().split())

ans = X // (Z + Y)
rest = X - (Z + Y) * ans

if rest // Z ==0:
    print(ans - 1)
else:
    print(ans)
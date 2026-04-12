x, y, z = map(int, input().split())
x -= 2*z
ans = 1
x -= y
ans += x//(y+z)
print(ans)

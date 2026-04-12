x,y,z = map(int,input().split())
ans = 0
x -= z
ans += int(x/(y+z))
print(ans)
x,y,z = map(int,input().split())
num = x-z
ans = 0
ans += num // (y+z)
print(ans)
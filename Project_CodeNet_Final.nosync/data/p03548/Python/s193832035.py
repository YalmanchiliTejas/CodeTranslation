x, y, z = map(int, input().split())

last = x - y - (z*2)
ans = int( last / (y+z) + 1)

print(ans)

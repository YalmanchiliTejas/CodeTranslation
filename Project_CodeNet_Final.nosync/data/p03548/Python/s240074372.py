x, y, z = map(int, input().split())
# x >= y*n + z*(n+1)
# x >= y*n + z*n + z
# (y+z)*n <=  x - z
# n <= (x-z)/(y+z)

print((x-z) // (y+z))
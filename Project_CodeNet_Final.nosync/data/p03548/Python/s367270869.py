x,y,z = map(int, input().split())
"""
n*y + z*(n+1) <= x
n(y+z) >= x + z
n <= (x+z) // (y+z)

"""

print((x-z)//(y+z))
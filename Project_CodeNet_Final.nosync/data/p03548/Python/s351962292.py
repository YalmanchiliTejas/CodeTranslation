import sys
line = sys.stdin.readline().strip()
x, y, z = map(int, line.split()[:3])
r = (x - z) // (y + z)
print(r)

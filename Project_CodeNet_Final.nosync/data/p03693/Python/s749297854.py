import sys

r, g, b = sys.stdin.readline().strip().split(" ")
n = int(r) * 100 + int(g) * 10 + int(b)

if n % 4 == 0:
    print("YES")
else:
    print("NO")

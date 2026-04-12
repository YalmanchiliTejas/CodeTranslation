import sys

r,g,b = map(str, sys.stdin.readline().split())

sum = int(r + g + b)

if sum % 4 == 0:
    print("YES")
else:
    print("NO")

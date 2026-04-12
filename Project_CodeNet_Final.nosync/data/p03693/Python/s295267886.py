import sys
input = sys.stdin.readline
r,g,b = [int(i) for i in input().split()]
d = 10 * g + b
if d % 4 == 0 :
    print("YES")
else :
    print("NO")
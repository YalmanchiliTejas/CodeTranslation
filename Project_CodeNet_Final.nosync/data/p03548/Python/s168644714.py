import sys
x,y,z = map(int, sys.stdin.readline().split())

ans = x // (y+z)

if x - ans * (y+z) < z:
    print(ans-1)
else:
    print(ans)
import sys
input = sys.stdin.readline
X, Y, Z = [int(x) for x in input().split()]
ans = 0
X -= Z
ans += (X // (Y + Z))
print(ans)
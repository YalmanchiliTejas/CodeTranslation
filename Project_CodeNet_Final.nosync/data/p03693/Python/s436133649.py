import sys
input = sys.stdin.readline
r = input().split()
if int("".join(r)) % 4 == 0:
    print("YES")
else:
    print("NO")
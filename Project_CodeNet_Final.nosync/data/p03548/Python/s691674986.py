import sys
input = sys.stdin.readline

x, y, z = map(int, input().split())
for i in range(1, x):
    if y * i + z * (i + 1) > x:
        print(i - 1)
        exit()

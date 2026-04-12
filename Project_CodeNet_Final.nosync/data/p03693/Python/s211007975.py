from sys import stdin

data = stdin.readline().rstrip().split()

total = 100 * int(data[0]) + 10 * int(data[1]) + int(data[2])
if total % 4 == 0:
    print("YES")
else:
    print("NO")

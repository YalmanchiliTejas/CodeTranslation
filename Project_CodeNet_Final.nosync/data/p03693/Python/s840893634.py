from sys import stdin

a, b, c = [int(x) for x in stdin.readline().rstrip().split()]
r = (a * 100) + (b * 10) + c
if r % 4 == 0:
    print("YES")
else:
    print("NO")

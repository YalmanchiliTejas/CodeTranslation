import sys
 
stdin = sys.stdin
 
ni = lambda: int(ns())
nin = lambda x: [ni() for _ in range(x)]
na = lambda: list(map(int, stdin.readline().split()))
nan = lambda x: [na() for _ in range(x)]
ns = lambda: stdin.readline().rstrip()
nas = lambda: stdin.readline().split()

x = ni()
flag = False
for i in range(3, 8, 2):
    if x == i:
        flag = True

if flag:
    print("YES")
else:
    print("NO")
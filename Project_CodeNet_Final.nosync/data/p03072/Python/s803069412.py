import sys

n = int(sys.stdin.readline())
matlist = list([int(i) for i in sys.stdin.readline().split()])

bef = 0
ans = 0
for i in range(n):
    tmp = matlist[i]
    if tmp >= bef:
        ans += 1
        bef = tmp

print(ans)

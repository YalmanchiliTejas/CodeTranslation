import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
n, x = [int(x) for x in input().split()]

total = [1]
p = [1]

for i in range(n):
    total.append(total[-1]*2 + 3)
    p.append(p[-1]*2 + 1)

ans = 0

# print(total)

def solve(x, i):
    global ans
    if x == 0:
        ans += 1
        return
    if i <= 1 + total[x - 1]:
        if i - 1 > 0:
            solve(x - 1, i - 1)
    else:
        ans += 1 + p[x - 1]
        if i - (2 + total[x - 1]) > 0:
            solve(x - 1, i - (2 + total[x - 1]))

solve(n, x)
print(ans)

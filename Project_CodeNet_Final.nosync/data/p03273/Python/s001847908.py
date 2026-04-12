import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


h, w = LI()
a = [list(S()) for _ in range(h)]
ans = [[a[j][i] for i in range(w)] for j in range(h)]
# is_white_line = [[False for _ in range(w)] for __ in range(h)]
# is_white_row = [[False for _ in range(h)] for __ in range(w)]

for i in range(h):
    is_white = True
    for j in range(w):
        if a[i][j] == '.':
            continue
        else:
            is_white = False
            break
    if is_white:
        ans[i] = [False] * w

for i in range(w):
    is_white = True
    for j in range(h):
        if a[j][i] == '.':
            continue
        else:
            is_white = False
            break
    if is_white:
        for j in range(h):
            # ans[i].pop(j)
            ans[j][i] = False

for i in range(w):
    is_white = True
    for j in range(h):
        if a[j][i] == '.':
            continue
        else:
            is_white = False
            break
    if is_white:
        for j in range(h):
            # ans[i].pop(j)
            ans[j][i] = False
res = ''
for i in range(h):
    if not(any(ans[i])):
        continue
    for j in range(w):
        if ans[i][j]:
            res += ans[i][j]
    res += '\n'
print(res.rstrip('\n'))

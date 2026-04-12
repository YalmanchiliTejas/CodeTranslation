nl = lambda: list(map(int, input().split()))
sl = lambda: input().split()
n = lambda: int(input())
s = lambda: input()

r, g, b = nl()

if (100*r + 10*g + b) % 4 == 0:
    print('YES')
else:
    print('NO')

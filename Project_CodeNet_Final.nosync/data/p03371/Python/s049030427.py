import sys


inint = lambda: int(sys.stdin.readline())
inintm = lambda: map(int, sys.stdin.readline().split())
inintl = lambda: list(inintm())
instrm = lambda: map(str, sys.stdin.readline().split())
instrl = lambda: list(instrm())

a, b, c, x, y = inintm()

ans = 0

for i in range(max(x, y)):
    if x != 0 and y != 0:
        if c*2 < a + b:
            ans += c*2
            x -= 1
            y -= 1
        else:
            ans = ans + a + b
            x -= 1
            y -= 1
    else:
        if x == 0:
            if c*2 < b:
                ans += c*2
                y -= 1
            else:
                ans += b
                y -= 1
        else:
            if c*2 < a:
                ans += c*2
                x -= 1
            else:
                ans += a
                x -= 1

print(ans)

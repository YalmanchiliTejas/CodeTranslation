import sys
input = sys.stdin.readline


def readstr():
    return input().strip()


def readint():
    return int(input())


def readnums():
    return map(int, input().split())


def readstrs():
    return input().split()


A, B, C, X, Y = readnums()

if A + B > C * 2:
    if X > Y:
        ans = min(C * 2 * Y + A * (X - Y), C * 2 * X)
    else:
        ans = min(C * 2 * X + B * (Y - X), C * 2 * Y)
else:
    ans = A * X + B * Y

print(ans)

import sys
input = sys.stdin.readline
from functools import lru_cache

@lru_cache(maxsize=None)
def solve(l):
    if l == 0:
        return 1, 1
    x, y = solve(l - 1)
    return x * 2 + 1, y * 2 + 3


def main():
    N, X = [int(x) for x in input().split()]
    b = []
    for y in range(51):
        b.append(solve(y))

    # print(b)
    ans = 0
    for y in range(N, -1, -1):
        if X >= b[y][1] * 2 + 1:
            X -= b[y][1]
            X -= b[y][1]
            ans += b[y][0]
            ans += b[y][0]
            ans += 1
        elif X >= b[y][1] + 1:
            X -= b[y][1]
            ans += b[y][0]
            ans += 1
            X -= 2
        elif X >= b[y][1]:
            X -= b[y][1]
            ans += b[y][0]
        else:
            X -= 1

    print(ans)




if __name__ == '__main__':
    main()


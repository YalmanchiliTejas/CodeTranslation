import sys
from enum import Enum

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    from itertools import product
    n = int(readline())
    s = input()

    for a, b in product(("S", "W"), repeat=2):
        kinds = [""] * n
        kinds[0] = a
        kinds[1] = b

        for i in range(1, n - 1):
            if kinds[i] is "S":
                if s[i] == "o":
                    kinds[i + 1] = kinds[i - 1]
                else:
                    if kinds[i - 1] == "S":
                        kinds[i + 1] = "W"
                    else:
                        kinds[i + 1] = "S"
            else:
                if s[i] == "o":
                    if kinds[i - 1] == "S":
                        kinds[i + 1] = "W"
                    else:
                        kinds[i + 1] = "S"
                else:
                    kinds[i + 1] = kinds[i - 1]
        ff = (s[n - 1] == "o") ^ (kinds[n - 1] == "W")
        fs = (s[0] == "o") ^ (kinds[0] == "W")
        f1 = False
        f2 = False
        if ff and (kinds[n - 2] == kinds[0]):
            f1 = True
        if not ff and (kinds[n - 2] != kinds[0]):
            f1 = True
        if fs and (kinds[n - 1] == kinds[1]):
            f2 = True
        if not fs and (kinds[n - 1] != kinds[1]):
            f2 = True

        if f1 and f2:
            res = "".join(kinds)
            print(res)
            sys.exit()
    print(-1)


if __name__ == '__main__':
    main()

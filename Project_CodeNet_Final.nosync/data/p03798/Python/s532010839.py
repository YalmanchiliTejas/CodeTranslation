import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(readline())
    s = input()

    if s[1] == "o":
        first = ((True, True, True),
                 (False, True, False),
                 (True, False, False),
                 (False, False, True))
    else:
        first = ((True, True, False),
                 (False, True, True),
                 (True, False, True),
                 (False, False, False))

    for a, b, c in first:
        kinds = [None] * (n + 1)
        kinds[1] = b
        kinds[0] = a
        kinds[2] = c

        for i in range(2, n):
            if kinds[i]:
                if s[i] == "o":
                    kinds[i + 1] = kinds[i - 1]
                else:
                    kinds[i + 1] = not kinds[i - 1]
            else:
                if s[i] == "o":
                    kinds[i + 1] = not kinds[i - 1]
                else:
                    kinds[i + 1] = kinds[i - 1]

        res = ""
        flag = True
        for i in range(n):
            left = kinds[(i - 1) % n]
            right = kinds[(i + 1) % n]
            res += "S" if kinds[i] else "W"
            if (s[i] == "o" and kinds[i]) or (s[i] == "x" and not kinds[i]):
                if left != right:
                    flag = False
                    break
            else:
                if left == right:
                    flag = False
                    break
        if flag:
            print(res)
            sys.exit()

    print(-1)


if __name__ == '__main__':
    main()

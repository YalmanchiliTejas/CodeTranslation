import math
import sys
import collections
import bisect
readline = sys.stdin.readline


def main():
    [n, s, k] = [str(readline().rstrip()) for _ in range(3)]
    s = list(s)
    strS = ""
    target = s[int(k) - 1]
    for i in range(int(n)):
        if s[i] == target:
            strS += s[i]
        else:
            strS += "*"
    print(strS)


if __name__ == '__main__':
    main()

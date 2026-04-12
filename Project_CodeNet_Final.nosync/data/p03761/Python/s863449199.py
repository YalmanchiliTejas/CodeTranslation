# ABC058C - 怪文書 / Dubious Document (ARC071C)
import sys
input = sys.stdin.readline

from collections import OrderedDict
from string import ascii_lowercase


def main():
    n = int(input())
    lst = [input().rstrip() for _ in range(n)]
    cnt = OrderedDict.fromkeys(ascii_lowercase, 0)
    for i in lst[0]:
        cnt[i] += 1

    for i in lst[1:]:
        tmp = OrderedDict.fromkeys(ascii_lowercase, 0)
        for j in i:
            tmp[j] += 1
        for i in cnt.keys():
            cnt[i] = min(cnt[i], tmp[i])

    ans = ""
    for i, j in cnt.items():
        ans += i * j
    print(ans)


if __name__ == "__main__":
    main()
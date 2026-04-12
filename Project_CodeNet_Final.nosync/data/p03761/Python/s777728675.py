# ABC058C - 怪文書 / Dubious Document (ARC071C)
import sys
input = sys.stdin.readline

from collections import Counter
from string import ascii_lowercase


def main():
    N = int(input())
    D = tuple(Counter(input()) for _ in range(N))
    ans = ""
    for s in ascii_lowercase:
        if all(s in d for d in D):
            ans += s * min(d[s] for d in D)
    print(ans)


if __name__ == "__main__":
    main()
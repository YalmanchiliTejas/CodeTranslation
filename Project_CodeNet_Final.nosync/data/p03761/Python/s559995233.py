# ABC058C - 怪文書 / Dubious Document (ARC071C)
import sys
input = sys.stdin.readline

from string import ascii_lowercase


def main():
    N = int(input())
    S = tuple(input() for _ in range(N))
    ans = ""
    for i in ascii_lowercase:
        if all(i in s for s in S):
            ans += i * min(s.count(i) for s in S)
    print(ans)


if __name__ == "__main__":
    main()
# ABC058C - 怪文書 / Dubious Document (ARC071C)
from functools import reduce


def main():
    N = int(input())
    if N == 1:
        print(*sorted(input()), sep="")
        return
    S = tuple(input() for _ in range(N))
    ch = sorted(reduce(lambda a, b: set(a) & set(b), S))
    ans = ""
    for i in ch:
        ans += i * min(s.count(i) for s in S)
    print(ans)


if __name__ == "__main__":
    main()
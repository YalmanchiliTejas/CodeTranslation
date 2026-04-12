# ABC058C - 怪文書 / Dubious Document (ARC071C)
def main():
    N = int(input())
    S = tuple(input() for _ in range(N))
    ans = ""
    for i in "abcdefghijklmnopqrstuvwxyz":
        if all(i in s for s in S):
            ans += i * min(s.count(i) for s in S)
    print(ans)


if __name__ == "__main__":
    main()
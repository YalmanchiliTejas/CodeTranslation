#!python3

LI = lambda: list(map(int, input().split()))

# input
N, M = LI()
AB = [LI() for _ in range(M)]

link = [[] for _ in range(N)]


def create_link():
    for a, b in AB:
        link[a - 1].append(b - 1)
        link[b - 1].append(a - 1)


def dfs(v=0, s=set()):
    s = s | {v}
    if len(s) == N:
        return 1
    ans = 0
    for u in link[v]:
        if u in s:
            continue
        ans += dfs(u, s)
    return ans


def main():
    create_link()
    ans = dfs()
    print(ans)


if __name__ == "__main__":
    main()

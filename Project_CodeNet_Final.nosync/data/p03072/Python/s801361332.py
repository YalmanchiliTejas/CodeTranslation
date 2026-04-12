from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    n = int(input())
    h = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        tmp = h[: i + 1]
        if h[i] == max(tmp):
            ans += 1
    print(ans)


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()

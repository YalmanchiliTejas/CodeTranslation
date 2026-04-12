import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    n, x = map(int, input().split())

    pb = [1]
    p = [1]
    for _ in range(n):
        pb.append(pb[-1] * 2 + 3)
        p.append(p[-1] * 2 + 1)

    ans = 0
    for _ in range(n):
        if x == 0:
            break
        if x >= pb[-2] + 2:
            x -= pb[-2] + 2
            ans += 1 + p[-2]
        else:
            x -= 1
        pb.pop(-1)
        p.pop(-1)

    if x >= 1:
        ans += 1

    print(ans)


if __name__ == '__main__':
    main()

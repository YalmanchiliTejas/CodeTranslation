import sys
sys.setrecursionlimit(10**9)
INF = 10**18


def input():
    return sys.stdin.readline().rstrip()


def main():
    N = int(input())
    H = list(map(int, input().split()))
    ans = 1
    for i in range(N):
        for j in range(i):
            if H[j] > H[i]:
                break
            if i == j+1:
                ans += 1
    print(ans)


if __name__ == '__main__':
    main()

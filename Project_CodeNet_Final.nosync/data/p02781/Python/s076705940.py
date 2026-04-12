import sys
sys.setrecursionlimit(500)


def calc(N, K):
    if len(N) < K or K <= 0:
        return 0
    tmp = 9 - int(N[0])
    for i in range(K-1):
        tmp *= 9 * (len(N) - 1 - i)
    for i in range(K-1):
        tmp //= (i+1)
    if N[0] != "0":
        return tmp + calc(N[1:], K-1)
    else:
        return tmp + calc(N[1:], K)


def main():
    N = input()
    K = int(input())
    if len(N) < K:
        print(0)
        return
    ans = 1
    for i in range(K):
        ans *= 9 * (len(N) - i)
    for i in range(K):
        ans //= (i+1)
    ans -= calc(N, K)
    print(ans)


if __name__ == "__main__":
    main()

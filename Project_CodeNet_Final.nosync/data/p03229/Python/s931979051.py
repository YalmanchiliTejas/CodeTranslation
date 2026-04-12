import sys
input = sys.stdin.readline


# 解説ACのつもり。場合分けがバヤで完全に無理
def main():
    N = int(input())
    A = []
    for _ in range(N):
        A.append(int(input()))
    A.sort()
    ans = 0
    m = N//2
    if N % 2 == 0:
        for i in range(m - 1):
            ans -= 2 * A[i]
        for i in range(m + 1, N):
            ans += 2 * A[i]
        ans -= A[m-1]
        ans += A[m]
    else:
        for i in range(m - 1):
            ans -= 2 * A[i]
        for i in range(m + 2, N):
            ans += 2 * A[i]
        a1 = ans - 2*A[m-1] + A[m] + A[m+1]
        a2 = ans - A[m-1] - A[m] + 2*A[m+1]
        ans = max(a1, a2)

    print(ans)


if __name__ == '__main__':
    main()

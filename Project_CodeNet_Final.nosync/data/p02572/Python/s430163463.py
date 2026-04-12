def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    ans = 0
    all_num = sum(A)
    for i in range(N, 1, -1):
        all_num -= A[i - 1]
        ans += A[i - 1] * all_num
    print(ans % (10 ** 9 + 7))


main()

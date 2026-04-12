def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = [0] * N
    for i in range(N):
        A[i] = int(input())

    A.sort()
    i = 0
    j = N-1
    ans = A[j] - A[i]
    while j - i > 2:
        ans += A[j] - A[i+1] + A[j-1] - A[i]
        i += 1
        j -= 1
    if j - i == 2:
        ans += max(A[i+1] - A[i], A[i+2] - A[i+1])
    print(ans)


if __name__ == '__main__':
    main()

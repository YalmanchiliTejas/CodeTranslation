def main():
    N = int(input())
    A = [int(a) for a in input().split()]

    sum_A = [0] + [0 for i in range(N + 1)]

    for i in range(1, N + 1):
        sum_A[i] = sum_A[i - 1] + A[i - 1]

    A = [0] + A
    ans = 0

    for i in range(1, N):
        ans += (A[i] * (sum_A[N] - sum_A[i]))

    print(ans % (10**9 + 7))
    
if __name__ == "__main__":
    main()
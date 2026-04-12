def main():
    N = int(input())
    A = list(map(int, input().split()))

    B = sum(A)
    answer = 0
    for i in range(0, N):
        answer += A[i] * (B - A[i])
        B -= A[i]

    answer %= (10 ** 9 + 7)

    print(answer)


if __name__ == "__main__":
    main()

# A1*A2 + A1*A3 + ... + A1*AN = A1 * (A2 + A3 + ... + AN)
# +
# A2*A3 + A2*A4 + ... +| A2*AN = A2 * (A3 + A4 + ... + AN)

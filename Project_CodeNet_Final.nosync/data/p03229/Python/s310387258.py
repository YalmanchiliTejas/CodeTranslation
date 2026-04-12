N = int(input())
A = sorted([int(input()) for _ in range(N)])

if len(A) % 2:
    print(
        max(
            2 * (sum(A[len(A) // 2:]) - sum(A[:len(A) // 2])) - A[len(A) // 2] - A[len(A) // 2 + 1],
            2 * (sum(A[len(A) // 2 + 1:]) - sum(A[:len(A) // 2 + 1])) + A[len(A) // 2 - 1] + A[len(A) // 2]
        )
    )
else:
    print(2 * (sum(A[len(A) // 2:]) - sum(A[:len(A) // 2])) + A[len(A) // 2 - 1] - A[len(A) // 2])
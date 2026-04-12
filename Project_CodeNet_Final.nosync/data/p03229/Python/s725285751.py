from sys import stdin

def main():
    N = int(input())
    A = list(map(int, stdin.read().splitlines()))

    if N == 2:
        print(abs(A[1] - A[0]))
        return

    k = [2] * N; k[0] = 1; k[-1] = 1
    i = -1
    for j in range(N):
        k[j] *= i
        i *= -1
    k.sort()

    A.sort()
    ans1 = 0
    for i, j in zip(A, k):
        ans1 += i * j

    ans2 = 0
    for i, j in zip(A[::-1], k):
        ans2 += i * (j * -1)

    print(max(ans1, ans2))

input = lambda: stdin.readline()
main()

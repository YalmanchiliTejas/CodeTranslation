import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    N = int(readline())
    A = list(int(readline()) for _ in range(N))
    A.sort(reverse=True)
    B = []
    C = []
    lb = 0
    rb = -1
    lc = 0
    rc = -1
    for i in range(N):
        if i % 2 == 0:
            B.append(A[lb])
            lb += 1
            C.append(A[rc])
            rc -= 1
        else:
            B.append(A[rb])
            rb -= 1
            C.append(A[lc])
            lc += 1
    ansb = 0
    for i in range(N - 2):
        ansb += abs(B[i] - B[i + 1])
    ansb += max(abs(B[0] - B[-1]), abs(B[-2] - B[-1]))

    ansc = 0
    for i in range(N - 2):
        ansc += abs(C[i] - C[i + 1])
    ansc += max(abs(C[0] - C[-1]), abs(C[-2] - C[-1]))


    print(max(ansb,ansc))


if __name__ == '__main__':
    main()

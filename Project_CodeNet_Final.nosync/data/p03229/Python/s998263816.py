# でつoO(YOU PLAY WITH THE CARDS YOU'RE DEALT..)
import sys
def main(N, A):
    A.sort()
    B = [A[i // 2] if i & 1 == 0 else A[-1 - i // 2] for i in range(N)]
    C = [A[i // 2] if i & 1 == 1 else A[-1 - i // 2] for i in range(N)]

    print(max(f(B), f(C)))

def f(L):
    res = 0
    for i in range(len(L) - 1):
        res += abs(L[i] - L[i - 1])
    return res

if __name__ == '__main__':
    input = sys.stdin.readline
    N = int(input())
    A = [int(input()) for _ in range(N)]
    main(N, A)

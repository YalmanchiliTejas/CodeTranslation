import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def debug():
    A = [x]
    for _ in range(n - 1):
        next_A = pow(A[-1], 2) % m
        A.append(next_A)
    print(sum(A))


def resolve():
    A = [x]
    target = 0
    for _ in range(n - 1):
        next_A = pow(A[-1], 2) % m
        if next_A == 0:
            print(sum(A))
            exit()
        if next_A in A:
            target = next_A
            break
        A.append(next_A)
    else:
        print(sum(A))
        exit()

    idx = A.index(target)
    loop_length = len(A) - idx
    q, r = divmod(n - len(A), loop_length)
    base = sum(A)
    plus = sum(A[idx:]) * q + (sum(A[idx:idx + r]) if r != 0 else 0)
    print(base + plus)


if __name__ == '__main__':
    n, x, m = map(int, input().split())
    resolve()


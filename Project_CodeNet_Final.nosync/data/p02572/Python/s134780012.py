def execute(N, A):
    dst = 0
    s = sum(A)
    for v in A:
        s -= v
        dst += v * s

    return dst % (10**9+7)

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))

    print(execute(N, A))
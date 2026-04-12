def main():

    N  = int(input())
    A = list(map(int, input().split()))

    mod = pow(10, 9) + 7
    k1, k2 = 0, 0
    l1, l2 = 0, 0
    for i in range(N):
        k1 += A[i] // mod
        k2 += A[i] % mod
        l1 += (l2 + A[i] * A[i]) // mod
        l2 = (l2 + A[i] * A[i]) % mod
    # print(k1, k2, l1, l2)

    u = (k2*k2 - l2)
    v = (k1 * k1 - l1) * mod
    return ((u + v) // 2) % mod

if __name__ == '__main__':
    print(main())

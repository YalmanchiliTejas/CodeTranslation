import numpy as np
def main():
    MOD = 10**9 + 7
    N = int(input())
    A = np.array(list(map(int, input().split())), dtype="i4")

    A = A % MOD
    rsumA = np.cumsum(A[::-1]) % MOD
    count = 0
    for i in range(len(A)-1):
        a = A[i]
        other = rsumA[len(A) - i - 2]
        count += (a * other) % MOD
    count %= MOD
    print(count)





if __name__ == '__main__':
    main()

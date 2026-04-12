# (a+b+c) mod n = (((a mod n)+b mod n )+c) mod n
from itertools import accumulate

def main():
    N = int(input())
    A = list(map(int,input().split()))

    acc = list(accumulate(A))
    mod = 10**9 + 7

    ans = 0

    for i in range(N-1):
        ans += A[i]*(acc[-1]-acc[i])
        ans %= mod

    print(ans)


if __name__ == "__main__":
    main()
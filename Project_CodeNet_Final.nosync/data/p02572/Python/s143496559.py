from sys import stdin
import itertools

def main():

    input = stdin.readline

    N = int(input())
    A = list(map(int,input().split()))

    mod = (10 ** 9) +7

    ans = 0

    total = sum(A)

    for i in range(N):
        total = total - A[i]
        ans = (ans + (A[i] * total)) % mod
        

    print(ans)


if __name__ == "__main__":
    main()
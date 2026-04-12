import sys

def main():
    N = int(input())
    A = list(map(int, input().split()))

    sum_A = sum(A)
    cum_A = [sum_A]
    for a in A[:N-1]:
        cum_A.append(cum_A[-1] - a)

    res = 0
    mod = 1000000007
    for i, a in enumerate(cum_A[1:]):
        res += A[i] * a
        res %= mod

    print(res)

if __name__ == "__main__":
    main()
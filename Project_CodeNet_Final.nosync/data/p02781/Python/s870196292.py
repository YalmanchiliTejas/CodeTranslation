from itertools import combinations

def c(N, K):
    for i, n in enumerate(N):
        if n != 0:
            break
    N = N[i:]
    a = len(N)
    if a < K:
        return 0
    if K == 1:
        return N[0] + 9 * (a - 1)
    return (N[0] - 1) * c([9] * (a - 1), K - 1) + c(N[1:], K - 1) + c([9] * (a - 1), K)

def main():
    N = list(map(int, input()))
    K = int(input())
    return c(N, K)
    

print(main())

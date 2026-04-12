#!/usr/bin/env python3
from collections import deque, Counter
from heapq import heappop, heappush
from bisect import bisect_right

def prime_factorize(N):
    prime_list = []
    while N % 2 == 0:
        prime_list.append(2)
        N //= 2
    f = 3
    while f**2 <= N:
        if N % f == 0:
            prime_list.append(f)
            N //= f
        else:
            f += 2
    if N != 1:
        prime_list.append(N)
    return prime_list

def main():
    N, K = map(int, input().split())
    if K == 0:
        print(N*N)
        exit()
    ans = 0
    for i in range(1,N+1):
        if i <= K:
            ans += N
        else:
            ans += K * (N//i) + min(K,N%i+1) - 1
        # print(ans)
    print(N*N - ans)

if __name__ == "__main__":
    main()

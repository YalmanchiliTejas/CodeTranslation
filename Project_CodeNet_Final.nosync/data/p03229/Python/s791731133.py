#!/usr/bin/env python3
from collections import deque, Counter
from heapq import heappop, heappush
from bisect import bisect_right

def main():
    N, *A = map(int, open(0))
    A.sort()
    ans = 0
    if N % 2 == 1:
        ans += sum(A[N//2:])*2 - sum(A[:N//2])*2
        ans -= A[N//2]+A[N//2+1]
    else:
        ans += sum(A[N//2:])*2 - sum(A[:N//2])*2
        ans -= A[N//2]-A[N//2-1]
    

    ans2 = 0
    if N % 2 == 1:
        ans2 += sum(A[N//2+1:])*2 - sum(A[:N//2+1])*2
        ans2 += A[N//2]+A[N//2-1]
    else:
        ans2 += sum(A[N//2:])*2 - sum(A[:N//2])*2
        ans2 += A[N//2-1]-A[N//2]

    print(max(ans,ans2))

if __name__ == "__main__":
    main()

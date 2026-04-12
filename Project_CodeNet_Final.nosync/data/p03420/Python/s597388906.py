import sys
from collections import deque

def solve():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    Ans = 0
    if K == 0: print(N ** 2)
    else:
        for b in range(K + 1, N + 1):
            Ans += (b - K) * (N // b)
            mod = N % b
            if mod >= K and mod > 0: Ans += mod - K + 1
        
        print(Ans)

    return 0

if __name__ == "__main__":
    solve()
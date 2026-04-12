import sys
from collections import deque

input = sys.stdin.readline

def main():
    N = int(input())
    A = []
    for _ in range(N):
        A.append(int(input()))
    A.sort()
    if N%2 == 0:
        Bp = A[N//2:]
        Bm = A[:N//2]
        ans = 2*sum(Bp) - min(Bp) - 2*sum(Bm) + max(Bm)
    else:
        Bp = A[N//2+1:]
        Bm = A[:N//2+1]
        cnt = 2*sum(Bp) - 2*sum(Bm) + sum(Bm[-2:])

        Cp = A[N//2:]
        Cm = A[:N//2]
        ans = max(cnt, 2*sum(Cp) - sum(Cp[:2]) - 2*sum(Cm))

    print(ans)
        
if __name__ == "__main__":
    main()

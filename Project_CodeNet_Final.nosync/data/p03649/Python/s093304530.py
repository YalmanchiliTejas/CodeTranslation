import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
lb, ub = max(0, sum(A) - N * (N-1)), sum(A)
for S in range(lb, ub+1):
    s = 0
    for a in A:
        x = (a + S) // (N + 1)
        if 0 <= a - (N + 1) * x + S <= N - 1:
            s += x
        else:
            break
    else:
        if S == s:
            print(S)
            break
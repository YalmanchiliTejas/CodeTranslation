import sys
I = list(map(int, input().split()))
N = I[0]
M = I[1]
if not 1 <= N or not N <= 100:
    print("error")
    sys.exit()
if not 0 <= M or not M <= N:
    print("error")
    sys.exit()
if N == M:
    print("Yes")
else:
    print("No")

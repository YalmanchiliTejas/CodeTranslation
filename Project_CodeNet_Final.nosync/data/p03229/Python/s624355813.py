N = int(input())
A = [int(input()) for i in range(N)]
A.sort()
As, Al = A[:N//2], A[N//2:]
Sum = 0
if N%2 == 0:
    for i in range(N//2 - 1):
        Sum += (Al[i+1] - As[i])*2
    Sum += Al[0] - As[-1]
else:
    S, L = 0, 0
    for i in range(N//2):
        S += (Al[i+1]-As[i])*2
        L += (Al[i+1]-As[i])*2
    L += Al[0]-Al[1]
    S += As[-1] - Al[0]
    Sum = max(L, S)
print(Sum)
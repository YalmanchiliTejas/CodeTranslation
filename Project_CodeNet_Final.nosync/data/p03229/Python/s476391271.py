import math
n = int(input())

A = [int(input()) for i in range(n)]

A.sort()

half = math.floor(n/2)
if n ==2:
    print(A[1]-A[0])
else:
    half_A = A[half]
    dif = A[half+1] - half_A*2 +A[half-1]
    if (n%2 == 1) & (dif>0):
        total = sum(A[half+1:])*2 - sum(A[:half-1])*2 -A[half] - A[half-1]
    elif (n % 2 == 1) & (dif<=0):
        total = sum(A[half+2:])*2 - sum(A[:half])*2 + A[half] + A[half+1]
    else:
        total = sum(A[half+1:])*2 - sum(A[:half-1])*2 -A[half-1] + A[half]
    
    print(total)

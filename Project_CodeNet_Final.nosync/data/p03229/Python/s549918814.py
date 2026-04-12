N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

ret1 = 0
i, j = 1, len(A) - 1
e1, e2 = A[0], A[0]
mode = 0

while i <= j :
    if i == j :
        ret1 += max(abs(e1-A[i]), abs(e2-A[i]))
        i += 1
    else :
        if mode == 0 :
            ret1 += abs(e1-A[j]) + abs(e2-A[j-1])
            e1, e2 = A[j], A[j-1]
            j -= 2
        else :
            ret1 += abs(e1-A[i]) + abs(e2-A[i+1])
            e1, e2 = A[i], A[i+1]
            i += 2
            
        mode ^= 1
        
ret2 = 0
i, j = 0, len(A) - 2
e1, e2 = A[-1], A[-1]
mode = 1

while i <= j :
    if i == j :
        ret2 += max(abs(e1-A[i]), abs(e2-A[i]))
        i += 1
    else :
        if mode == 0 :
            ret2 += abs(e1-A[j]) + abs(e2-A[j-1])
            e1, e2 = A[j], A[j-1]
            j -= 2
        else :
            ret2 += abs(e1-A[i]) + abs(e2-A[i+1])
            e1, e2 = A[i], A[i+1]
            i += 2
            
        mode ^= 1
        
print(max(ret1, ret2))
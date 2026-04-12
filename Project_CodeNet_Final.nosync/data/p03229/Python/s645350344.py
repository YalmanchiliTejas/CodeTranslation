def calc(A):
    res = 0
    
    for i in range(N-1):
        res += abs(A[i+1]-A[i])
    
    return res

N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()

if N%2==0:
    l1 = A[:N//2]
    l2 = A[N//2:]
    l1.reverse()
    l2.reverse()
    B = [-1]*N
    
    for i in range(N):
        if i%2==0:
            B[i] = l1[i//2]
        else:
            B[i] = l2[i//2]
            
    ans = calc(B)
    print(ans)
else:
    l1 = A[:N//2]
    l2 = A[N//2:]
    B = [-1]*N
    B[0] = l2[0]
    B[-1] = l2[1]
    
    for i in range(1, N-1):
        if i%2==0:
            B[i] = l2[i//2+1]
        else:
            B[i] = l1[i//2]
    
    l1 = A[:N//2+1]
    l2 = A[N//2+1:]
    C = [-1]*N
    C[0] = l1[-1]
    C[-1] = l1[-2]
    
    for i in range(1, N-1):
        if i%2==0:
            C[i] = l1[i//2-1]
        else:
            C[i] = l2[i//2]
   
    ans = max(calc(B), calc(C))
    print(ans)
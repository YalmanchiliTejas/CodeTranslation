N = int(input())
A = sorted(int(input()) for TN in range(0,N))
if N%2==0:
    S = A[:(N//2)]
    B = A[(N//2):]
    SS = -2*sum(S)+S[-1]
    BS = 2*sum(B)-B[0]
    PT = SS+BS
    print(PT)
else:
    S = A[:(N//2)]
    B = A[(N//2):]
    SS1 = -2*sum(S)
    BS1 = 2*sum(B)-B[0]-B[1]
    PT1 = SS1+BS1
    
    SS2 = -2*sum(S)+S[-1]
    BS2 = 2*sum(B)-3*B[0]
    PT2 = SS2+BS2
    print(max(PT1,PT2))
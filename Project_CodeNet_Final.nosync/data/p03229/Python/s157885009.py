N = int(input())
A = sorted([int(input()) for _ in range(N)])
if N%2==0:
    B = A[:N//2]
    C = A[N//2:]
    C = C[::-1]
    D1 = []
    D2 = []
    for i in range(N//2-1):
        D1.append(B[i])
        D1.append(C[i])
        D2.append(C[i])
        D2.append(B[i])
    D1.append(B[-1])
    D1.insert(0,C[-1])
    D2.append(C[-1])
    D2.insert(0,B[-1])
    cnt1 = 0
    cnt2 = 0
    for i in range(1,N):
        cnt1 += abs(D1[i]-D1[i-1])
        cnt2 += abs(D2[i]-D2[i-1])
    print(max(cnt1,cnt2))
else:
    B = A[:N//2]
    C = A[N//2+1:]
    C = C[::-1]
    D1 = []
    D2 = []
    for i in range(N//2):
        D1.append(B[i])
        D1.append(C[i])
        D2.append(C[i])
        D2.append(B[i])
    cnt1 = 0
    cnt2 = 0
    for i in range(1,N-1):
        cnt1 += abs(D1[i]-D1[i-1])
        cnt2 += abs(D2[i]-D2[i-1])
    cnt1 += max(A[N//2]-D1[0],D1[-1]-A[N//2])
    cnt2 += max(D2[0]-A[N//2],A[N//2]-D2[-1])
    print(max(cnt1,cnt2))
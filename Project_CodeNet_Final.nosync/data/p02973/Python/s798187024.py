N = int(input())
A = [int(input()) for _ in range(N)]

B = [A[0]]

for i in range(1,N):
    if A[i]<=B[-1]:
        B.append(A[i])
    elif A[i]>B[0]: 
        B[0] = A[i]
    else:
        l = 0
        r = len(B)-1
        while l+1<r:
            c = (l+r)//2
            if B[c]>=A[i]:
                l = c
            else:          
                r = c
        if B[l]<A[i]:
            B[l] = A[i]
        else:
            B[r] = A[i]
print(len(B))

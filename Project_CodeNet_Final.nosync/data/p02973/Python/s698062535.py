
def bisect(a,B,lo,hi):
    if hi-lo<=1:
        return hi
    elif B[(hi+lo)//2]>=a:
        return bisect(a,B,(hi+lo)//2,hi)
    else:
        return bisect(a,B,lo,(hi+lo)//2)

N = int(input())

A = [int(input()) for i in range(N)]

B = [A[0]]

for i in range(1,N):
    if B[-1]>=A[i]:
        B.append(A[i])
    else:
        if B[0]<A[i]:
            B[0]=A[i]
        else: 
            B[bisect(A[i],B,0,len(B)-1)]=A[i]
print(len(B))
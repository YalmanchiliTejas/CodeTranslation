N = int(input())
A = [int(input()) for _ in range(N)]
A = sorted(A)
B = list(reversed(A))
ans = -1
#print(A)
#print(B)
if(N % 2 == 0):
    k = N//2
    typeN = -(2*sum(A[:k])+A[k]) + (2*sum(B[:k])+B[k])
    ans = typeN
else:
    k = N//2
    typeW = (2*sum(B[:k-1])+B[k-1]+B[k]) - (2*sum(A[:k]))
    typeM = (2*sum(B[:k])) - (2*sum(A[:k-1])+A[k-1]+A[k])
    ans = max(typeW,typeM)
print(ans)
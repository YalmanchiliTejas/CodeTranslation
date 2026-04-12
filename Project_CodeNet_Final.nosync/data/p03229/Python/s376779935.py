N=int(input())
A=[]
for i in range(N):
    A.append(int(input()))
A.sort()
z=N//2
if not N%2==0:
    An=sum(A[z+2:])*2 - sum(A[:z-1])*2 - A[z-1] + A[z+1] + max(-A[z-1]+A[z], -A[z] + A[z+1])
else:
    An=sum(A[z+1:])*2-sum(A[:z-1])*2-A[z-1]+A[z]
print(An)
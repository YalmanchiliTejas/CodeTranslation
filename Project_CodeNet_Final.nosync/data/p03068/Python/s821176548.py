N=int(input())
A=input()
x=int(input())

for i in range(N):
    if A[i]!=A[x-1]:
        A=A.replace(A[i],"*")
        
print(A)

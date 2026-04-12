n=int(input())
A=list(map(int,input().split()))
MOD = 1000000007
B=0
tem = sum(A)
for i in range(len(A)):
    tem -= A[i]
    B+= (A[i]%MOD)*(tem%MOD)
print(B%MOD)
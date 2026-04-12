A,B,C,X,Y = list(map(int,input().split()))
MIN = float('inf')
for i in range(0,max(X,Y)*2+2,2):
    MIN = min(MIN,max(A*(X-i//2),0)+max(B*(Y-i//2),0)+i*C)
print(MIN)
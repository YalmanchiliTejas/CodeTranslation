N = int(input())
A =[0]*N
for i in range(N):
    A[i] = int(input())
A.sort(reverse=True)
X=0
Y=0
if N % 2 == 0:
    for i in range(N//2-1):
        X = X + 2*A[i] -2*A[-i-1]
    X = X + A[N//2-1] -A[N//2]
    print(X)    

if N % 2 == 1:
        for i in range(N//2):
            X = X + 2 * A[i]
            Y = Y - 2 * A[-i-1]
        for i in range (N//2-1):
            X = X - 2 * A[-i-1]
            Y = Y + 2 * A[i]
        X = X - A[N//2] - A[N//2+1]
        Y = Y + A[N//2-1] + A[N//2]
        print(max(X,Y))
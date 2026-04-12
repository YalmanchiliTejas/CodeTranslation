N = int(input())
A = list(map(int,input().rstrip().split()))
X = 1
count = 0
for i in range(1,N):
    count = 0
    for k in range(i):
        if A[k] <= A[i]:
            count = count + 1
            if count == i:
                X = X + 1
                
                
print(X)
    
    
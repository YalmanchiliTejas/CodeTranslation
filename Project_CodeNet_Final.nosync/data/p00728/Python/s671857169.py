ans = []
while True:
    N = int(input())
    if N == 0:
        break
    
    A = sorted([int(input()) for i in range(N)])
    ans.append(sum(A[1:-1]) // (N - 2))
        
[print(i) for i in ans]

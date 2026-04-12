N = int(input())
A = list(map(int, input().split()))
ans = 0
while True:
    S = 0
    for i, a in enumerate(A):
        if a>=N:
            res = (a-N+1)//(N+1)+1
            A[i]-=res*(N+1)
            S+=res
    A = list(map(lambda x:x+S, A))
    ans+=S
    if all(a<N for a in A):
        break
print(ans)
    
            
    

    
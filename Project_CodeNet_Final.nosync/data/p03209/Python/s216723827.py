N,X = [int(i) for i in input().split()]
ans = 0
while N > 0:
    if X >= 2**(N+2) - 4: #N=2 12 N=1 4
        ans += 2**(N+1) - 1
        break
    
    elif X > 2**(N+1) - 1: #N=2 7
        ans += 2**N
        X -= 2**(N+1) - 1
        
    elif X == 2**(N+1) - 1: #N=2 7
        ans += 2**N
        break
    
    elif X == 2**(N+1) - 2: #N=2 6
        ans += 2**N - 1
        break
    
    elif X > 1:
        X -= 1
        
    else:
        break
    N -= 1
print(ans)
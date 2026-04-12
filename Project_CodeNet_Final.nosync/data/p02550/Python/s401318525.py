N, X, M = map(int,input().split())
ans = 0
ls = [X%M] + [-1]*(M+1)
ls_app = [0]*(M+1)

for i in range(N):
    a = ls[i]
    ls_app[a] = i
    ls[i+1] = pow(a,2,M)
    if i+1 < N and ls_app[ls[i+1]] != 0:
        b = ls[i+1]
        L = ls_app[b]
        R = i
        len_roop = R - L + 1
        p = (N - L) // len_roop
        q = (N - L) % len_roop
        break
else:
    for i in range(N):
        ans += ls[i]
    print(ans)   
    exit()
    
sum_roop = 0        
for i in range(L, R+1):
    sum_roop += ls[i]
    
sum_edge = 0
for i in range(L, L+q):
    sum_edge += ls[i] 
    
for i in range(L):
    ans += ls[i]
else:
    ans += sum_roop * p + sum_edge        
    
print(ans) 
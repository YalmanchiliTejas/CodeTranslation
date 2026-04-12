N, X, M = map(int, input().split())

ans = 0
C = [0]
Xd = [-1] * (M+1)

for i in range(N):
    x = X if i==0 else x**2 % M
    
    if Xd[x] > -1:
        break
    Xd[x] = i
    ans += x
    C.append(ans)

loop_len = i - Xd[x]
if loop_len > 0:
    S = C[i] - C[Xd[x]]
    loop_num = (N - i) // loop_len
    ans += loop_num * S
    m = N - loop_num * loop_len - i
    ans += C[Xd[x]+m] - C[Xd[x]]

print(ans)
import sys
readline = sys.stdin.readline

N, X, M = map(int, readline().split())

table = [0]*M
for x in range(M):
    table[x] = x*x%M

if N <= M:
    ans = 0
    x = X
    for _ in range(N):
        ans += x
        x = table[x]
    
else:
    ans = 0
    x = X
    for _ in range(M):
        ans += x
        x = table[x]
    N -= M
    res = 0
    vx = x
    st = []
    for loop in range(1, M+1):
        st.append(x)
        x = table[x]
        if x == vx:
            break
    
    ans += sum(st)*(N//loop) + sum(st[:N%loop])
print(ans)
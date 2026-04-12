N, X, M = map(int, input().split())
T = []
K = [0]*M
p = X
for i in range(N):
    if K[p] == 1:
        break
    else:
        T.append(p)
    K[p] = 1
    p *= p
    p %= M

for i in range(N):
    if T[i] == p:
        break
ans = 0
ans += sum(T)
if N > len(T):
    L = sum(T[i:])
    q = len(T[i:])
    ans += L*((N-len(T))//q)
    ans += sum(T[i:i+(N-len(T)) % q])
print(ans)
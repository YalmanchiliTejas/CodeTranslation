N, X, M = map(int, input().split())
hist = [-1] * (M + 1)
ans = X; hist[X] = 0; A = [X]
r = X % M
i = 1
N -= 1
while N:
    nxt = (r * r) % M
    if hist[nxt] != -1:
        break
    ans += nxt
    hist[nxt] = i; A.append(nxt); i += 1
    r = nxt; N -= 1
if N:
    A_sub = A[hist[nxt]:]
    L = len(A_sub)
    q, rem = divmod(N, L)
    ans += sum(A_sub) * q + sum(A_sub[:rem])
print(ans)
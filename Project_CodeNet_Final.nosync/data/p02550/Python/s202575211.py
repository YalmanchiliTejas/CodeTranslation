N, X, M = map(int, input().split())

acc = [0]
S = dict()
Ai = X
i = 0
while Ai not in S:
    S[Ai] = i
    acc.append(acc[-1] + Ai)
    i += 1
    Ai = (Ai * Ai) % M

t = S[Ai]
T = i - t
if N <= t:
    ans = acc[N]
else:
    ans = acc[t] + (acc[-1] - acc[t]) * ((N - t) // T) 
    if (N - t) % T > 0:
        ans += acc[((N - t) % T) + t] - acc[t]
print(ans)

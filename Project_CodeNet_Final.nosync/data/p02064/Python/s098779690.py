N, s, t = map(int, input().split())
dists = [0]*(N+1)
distt = [0]*(N+1)
for i in range(1, N+1):
    if i == s:
        continue
    print('?', s, i, flush = True)
    dists[i] = int(input())

for i in range(1, N+1):
    if i == t:
        continue
    print('?', t, i, flush = True)
    distt[i] = int(input())

D = dists[t]
U = []
for i in range(1, N+1):
    if dists[i] + distt[i] == D:
        U.append(i)
Q = sorted([(dists[u], u) for u in U])
Q = [q[1] for q in Q][::-1]
Q.remove(s)
Q.remove(t)
Ans = [s]
while Q:
    q = Q.pop()
    pre = Ans[-1]
    print('?', q, pre, flush = True)
    e = int(input())
    if dists[pre] + e + distt[q] == D:
        Ans.append(q)
Ans.append(t)
print('!', *Ans, flush = True)


N, = map(int, input().split())
xs = list(map(int, input().split()))
r = 0
for k in range(1, N):
    a = (N-1) % k
    b = a - k
    n = (N-1-a)//k
    if a <= k:
        a += k
    if a <= k:
        a += k

    for _ in range((N-1-a)//k):
        b = a - k
        n = (N-1-a)//k
        if a <= b:
            a += k
            continue
        if a%(a-b) == 0:
            if a <= (a-b)*n:
                a += k
                continue
    if a <= b or a >= N-1:
        continue
    s1 = a
    s2 = n * (a-b)
    t = xs[s1]
    ps = [(s1,t)]
    for i in range(n):
        s1 += a-b
        t += xs[s2]
        t = max(t,0)
        t += xs[s1]
        ps.append((s2,xs[s2]))
        ps.append((s1,xs[s1]))
        s2 -= a-b
    #print(ps, t)
    r = max(r, t)

print(r)

N, = map(int, input().split())
xs = list(map(int, input().split()))
r = 0
for k in range(1, N):
    a = (N-1) % k
    for _ in range(1+(N-1-a)//k):
        b = a - k
        n = (N-1-a)//k
        if a <= b or a <= k:
            a += k
            continue
        if a%(a-b) == 0:
            if a <= (a-b)*n:
                a += k
                continue
    if a >= N-1:
        continue
    s1 = a
    s2 = n * (a-b)
    t = xs[s1]
    for i in range(n):
        s1 += a-b
        t += xs[s2]
        t = max(t,0)
        t += xs[s1]
        s2 -= a-b
    r = max(r, t)
print(r)

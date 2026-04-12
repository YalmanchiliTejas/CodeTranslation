H,W = map(int, input().split())
A = [input() for _ in range(H)]
ind_H = []
ind_W = []
for h,a in enumerate(A):
    if '#' in a:
        ind_H.append(h)
        for w,s in enumerate(a):
            if s == '#':
                ind_W.append(w)
for h in ind_H:
    ans = ''
    for w in range(W):
        if w in ind_W:
            ans += A[h][w]
    print(ans)

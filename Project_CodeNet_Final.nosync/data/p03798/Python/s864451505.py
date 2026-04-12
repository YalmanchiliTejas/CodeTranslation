def check(prev_, now_, S, N):
    rev = {'S':'W', 'W':'S'}
    prev, now = prev_, now_
    p  = [now]
    for i in range(1,N+1):
        if S[i] == 'o':
            if now == 'S':
                prev, now = now, prev
            else:
                prev, now = now, rev[prev]
        else:
            if now == 'S':
                prev, now = now, rev[prev]
            else:
                prev, now = now, prev
        p.append(now)
    if prev_ == prev and now_ == now:
        print(''.join(p[:-1]))
    return prev_ == prev and now_ == now

N=int(input())
S=input()
S = S[-1]+S+S[0]

ptn = ['SS', 'SW', 'WS', 'WW']
for sw in ptn:
    if check(sw[0], sw[1], S, N):
        break
else:
    print(-1)
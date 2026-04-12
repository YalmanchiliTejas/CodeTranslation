dic = {'North' : 0, 'East' : 1, 'South' : -2, 'West' : -1}

vv = []
while True:
    n = int( raw_input() )
    if n == 0: break
    cur = 1
    adj = [2, 4, 5, 3]
    ans = 1
    for i in range(n):
        cmd = raw_input()
        if cmd in ['North', 'East', 'South', 'West']:
            cur, adj[ dic[cmd] ], adj[ dic[cmd] + 2 ] = adj[ dic[cmd] ] , 7-cur, cur
        elif cmd == 'Left':
            adj = adj[1:] + adj[:1]
        elif cmd == 'Right':
            adj = adj[-1:] + adj[:-1]
        ans += cur
    vv.append(ans)
for v in vv:
    print v
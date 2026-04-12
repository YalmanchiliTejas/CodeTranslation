import sys
import queue
h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
d = queue.Queue()
d.put([0, 0, 0])
vals = set()

while not d.empty():
    now = d.get()
    a[now[0]][now[1]] = '.'
    if now[2] in vals:
        print('Impossible')
        sys.exit()
    else:
        vals.add(now[2])
        
    if now[0] == h-1 and now[1] == w-1:
        a1 = [['.']*w for _ in range(h)]
        if a == a1:
            print('Possible')
        else:
            print('Impossible')
        sys.exit()
    else:
        if now[0]+1 < h:
            if a[now[0]+1][now[1]] == '#':
                d.put([now[0]+1, now[1], now[2]+1])
        if now[1]+1 < w:
            if a[now[0]][now[1]+1] == '#':
                d.put([now[0], now[1]+1, now[2]+1])        
print('Impossible')

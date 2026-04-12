import os
import sys
from atexit import register
from io import BytesIO
sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))
input = lambda: sys.stdin.readline().rstrip('\r\n')
raw_input = lambda: sys.stdin.readline().rstrip('\r\n')

n,x,m = (int(x) for x in input().split())
lst = []
ans = 0
cnt = 0
i = 0
visited = [-1 for _ in xrange(m)]
stop_c = False
while i < n:
    if i == 0:
        ret = pow(x,1,m)
    else:
        ret = pow(x,2,m)
    x = ret
    if visited[ret] == -1:
        visited[ret] = i
    else:
        stop_c = True
        # i += 1
        break
    ans += ret
    lst.append(ret)
    i += 1

if stop_c:
    cycle_len = len(lst[visited[ret]:])
    cycle_sum = sum(lst[visited[ret]:])
    remsum  = sum(lst[visited[ret]:][:(n-visited[ret]) % cycle_len])
    print((ans -cycle_sum) + (cycle_sum * ((n-visited[ret]) // cycle_len)) + remsum)
else:
    print(ans)
#!/usr/bin/env python3
#ABC64 A

r,g,b = map(int,input().split())

x = str(r)+str(g)+str(b)
if int(x) % 4 == 0:
    print('YES')
else:
    print('NO')

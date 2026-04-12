# -*- coding: utf-8 -*-
x,y,z = map(int,input().split())
ans = int(x/(y+z))
if (y+z) * ans + z > x:
    ans += -1
print(ans)
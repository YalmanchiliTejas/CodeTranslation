# -*- coding: utf-8 -*-

x, y, z = list(map(int,input().split()))

ans = 0
while(x>=z+ans*(y+z)):
    ans += 1
        
print(ans-1)

    
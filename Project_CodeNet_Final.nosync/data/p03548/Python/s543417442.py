#!/usr/bin/env python3

x,y,z = list(map(int,input().split(" ")))

ans = 0#人の数
for i in range(10**5):
    ans += 1
    if ans*y + z*(ans+1) > x:
        break
print(ans-1)
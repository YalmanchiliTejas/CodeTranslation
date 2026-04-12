# -*- coding: utf-8 -*-
import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N, X, M = map(int, readline().split())
ans = X
x = X
data = [0]*M
data[x] = 0
t = [x]
for i in range(1,N):
    nx = x ** 2 % M     
    if nx == 0:
        break
    if data[nx] != 0:
        res = N-i
        s = i-data[nx]
        syuki_cnt = res // s
        rem_cnt = res % s
        nt = t[data[nx]:i]
        ans += sum(nt)*syuki_cnt+sum(nt[:rem_cnt])
        break
    ans += nx
    x = nx
    data[nx] = i
    t.append(nx)
print(ans)
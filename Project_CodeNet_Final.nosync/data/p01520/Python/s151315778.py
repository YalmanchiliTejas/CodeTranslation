# coding: utf-8
# Your code here!

N, T, E = map(int, input().split())
# N：砂時計の個数
# T：理想の茹で時間
# E：許容誤差

time = list(map(int, input().split()))

min = T - E
max = T + E 

c = [0] * 100
for i in range(len(time)):
   for j in range(min, max + 1):
      if j % time[i] == 0:
         c[i] += 1

if sum(c) == 0:
   print(-1)
else:
   for i in range(len(c)):
      if c[i] > 0:
         print(i + 1)
         break


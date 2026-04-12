import math
import sys
n = int(input())
li = list(map(int, input().split()))
cnt = 0
maximum = 0
for i in li:
    if (maximum <= i):
        cnt += 1
        maximum = i
print(cnt)
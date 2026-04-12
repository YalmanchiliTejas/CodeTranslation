# coding: utf-8
n = int(input())
data = list(map(int, input().split()))
cnt = 0
h = 0
for i in range(n):
    if data[i] >= h:
        cnt += 1
        h = data[i]
print(cnt)

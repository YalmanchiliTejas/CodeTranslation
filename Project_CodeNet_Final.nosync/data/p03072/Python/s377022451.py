#coding: utf-8
N = int(input())
h = list(map(int, input().split()))
cnt = 1
for i in range(1, N):
    tmp = 0
    for j in range(i+1):
        if h[j] > h[i]:
            tmp += 1
    if tmp == 0:
        cnt += 1
print(cnt)
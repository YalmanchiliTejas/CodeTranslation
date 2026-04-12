# coding: utf-8

n = input()
h = list(map(int, input().split()))

max = h[0]
cnt = 1

for i in range(len(h)-1):
  if max <= h[i+1]:
    max = h[i+1]
    cnt += 1

print(cnt)
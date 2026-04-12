# -*- coding: utf-8 -*-

N = int(input().strip())
H_list = list(map(int, input().rstrip().split()))
#-----

max_H=0
cnt=0
for i in H_list:
    if i >= max_H:
        cnt += 1
        max_H = i

print(cnt)

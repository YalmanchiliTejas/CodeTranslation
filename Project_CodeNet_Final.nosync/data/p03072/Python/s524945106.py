# -*- coding:utf-8 -*-

n = int(input())
h = input().split()
h_int = [int(i) for i in h]
count = 0
flag = 0

for i in range(n):
    #print(i)
    for j in range(i):
        if h_int[i] < h_int[i-1-j]:
            #print("{} {}".format(h[i-j], h[i]))
            flag = 1
            break
    if flag == 0:
        count += 1
    else:
        flag = 0

print(count)
# -*- coding: utf-8 -*-
n = int(input())
h = list(map(int, input().split()))
counter = 0
for i in h:
    if counter == 0:
        counter = counter + 1
        max_h = i
    else:
        if max_h <= i:
            counter = counter + 1
            max_h = i
        else:
            pass
print(counter)
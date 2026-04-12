#! -*- coding: utf-8 -*-

import numpy as np
import copy

n = int(raw_input())
x = map(int,raw_input().split())

x_min = copy.copy(x)
x_max = copy.copy(x)

x_min.remove(max(x))
x_max.remove(min(x))

med_x_min = int(np.median(x_min))
med_x_max = int(np.median(x_max))

if med_x_max == med_x_min:
    for i in range(n):
        print med_x_max
else:
    for i in range(n):
        if x[i] >= med_x_max:
            print med_x_min
        else:
            print med_x_max

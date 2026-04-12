# -*- coding: utf-8 -*-
import math

X, Y, Z = map(int, input().split())
chair = X - Z

num = math.floor(chair / (Y+Z))

print(num)
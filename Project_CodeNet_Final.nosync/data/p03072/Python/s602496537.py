#!/usr/bin/env python3

import re

a = int(input())

b = input()
b = re.split(" ",b)

max = int(b[0])
ans = 0
for i in range(a):
    if(int(b[i]) >= max):
        max = int(b[i])
        ans += 1
print(ans)

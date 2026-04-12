# -*- coding: utf-8 -*-

N = int(input())
S = input()
K = int(input())

s = S[K - 1]

import re
ans = re.sub(r'[^{}]'.format(s), '*', S)
print(ans)

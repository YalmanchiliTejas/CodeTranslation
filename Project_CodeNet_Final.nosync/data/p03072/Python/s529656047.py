import numpy as np
from collections import defaultdict
from collections import Counter
from collections import OrderedDict
#key = {1:2, 2:5, 3:5, 4:4, 5:5, 6:6, 7:3, 8:7, 9:6}
N = int(input())
#H = (int(i) for i in input().split())
#H = (int(input().split()))
H=list(map(int, input().split()))  #リスト入力
#print(H)
cnt = 0
for i, h in enumerate(H):
    if i == 0:
        max_h = H[0]
        cnt += 1
        continue
    else:
        if max_h <= h:
            cnt += 1
            max_h = h
print(cnt)
import numpy as np

n = int(input())
h_list = list(map(int,input().split()))
h = np.array(h_list)

can_see = 1  # 海の見える旅館の数  # 一番最初の旅館からは必ず見える
for i in range(1, n):
    if not np.any((h > h[i])[:i]):
        can_see+=1

print(can_see)
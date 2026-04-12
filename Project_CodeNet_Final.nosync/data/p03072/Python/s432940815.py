#!/usr/bin/env python
# -*- coding: utf-8 -*-

N=int(input())
heights = list(map(int,input().split()))  # N, H1, H2.... 複数行入力
ans = 0  # 一番左
max_height = heights[0]  # 一番西の建物が最大

for i in range(N):
    max_height = max(max_height,heights[i])
    if max_height == heights[i]:  # 更新
        ans += 1

print(ans)
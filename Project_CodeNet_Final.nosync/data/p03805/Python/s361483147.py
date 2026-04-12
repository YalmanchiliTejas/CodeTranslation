#!/usr/bin/env python
# -*- coding: utf-8 -*-

import itertools

n, m = map(int, input().rstrip().split())
adjacency_matrix = [[0 for i in range(n)] for i in range(n)]

# 隣接行列を作る
for i in range(m):
    a, b = map(int, input().rstrip().split())
    adjacency_matrix[a-1][b-1] = 1
node = [i for i in range(1, n)]

result = 0
# 全組み合わせを試す
for v in itertools.permutations(node):
    index = 0
    adj_mat2 = adjacency_matrix[:]
    past = 0
    for i in v:
        # 隣接行列右上を参照する
        # そのときa>bでadj_mat[a][b]
        a = min(past, i)
        b = max(past, i)


        if adj_mat2[a][b] != 1:
            break

        past = i
        index += 1
    if index == n-1:
        result += 1

print(result)

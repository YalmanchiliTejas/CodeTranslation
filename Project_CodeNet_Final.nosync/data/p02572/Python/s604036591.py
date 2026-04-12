# -*- coding: utf-8 -*-
N = int(input())
num_list = list(map(int, input().split(' ')))

list_sum = sum(num_list)

ans = 0
for i in range(N-1):
    list_sum -= num_list[i]
    ans += num_list[i] * list_sum

print(ans % (10**9 + 7))
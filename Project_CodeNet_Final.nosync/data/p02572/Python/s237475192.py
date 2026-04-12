# -*- coding: utf-8 -*-
N = int(input())
A_list = list(map(int, input().split()))

div_num = 10 ** 9 + 7
sum_rest = sum(A_list)
ans = 0
for i in range(N):
    sum_rest -= A_list[i]
    ans = (ans + A_list[i] * sum_rest) % div_num

print(ans)
#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**6)

n, x, m = list(map(int, input().split()))

data = [-1]*(m+1)

ans = x

num = x
data[x] = (1, 0)
count = 2

flag = 0
while(count <= n):
    # print(count)
    num_new = (num**2) % m
    if data[num_new] == -1 or flag == 1:
        data[num_new] = (count, ans)
        ans += num_new
        num = num_new
    else:
        diff = ans-data[num_new][1]
        frec = count - data[num_new][0]

        kaisuu = (n-(count-1))//frec

        if kaisuu > 0:
            count = count-1 + frec*kaisuu
            ans += kaisuu*diff
        else:
            ans += num
            num = num_new
        flag = 1
    count += 1

# print(count, n)
# print(flag, ans)
print(ans)

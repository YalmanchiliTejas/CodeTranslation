#! -*- coding:utf-8 -*-
n = int(input())
S = [''] * n
m = 51
for i in range(n):
    S[i] = list(str(input()))
    if m > len(S[i]):
        m = len(S[i])
arr = []
for i in range(len(S[0])):
    x = S[0][i]
    flag = 0
    count = 0
    for j in range(2,n):
        count += 1
        for k in range(len(S[j])):
            if S[j][k] == x:
                flag += 1
                S[j][k] = ''
                break
    if flag == count:
        arr.append(x)

arr.sort()
res = "".join(arr)
print(res)

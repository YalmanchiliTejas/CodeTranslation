"""
賢過ぎる解法.汎用性が高そう.
"""
from bisect import bisect

N = int(input())
inputs = [-int(input()) for _ in range(N)]

data = [inputs[0]]
for i in range(1, N):
    index = bisect(data, inputs[i])
    if index == len(data):
        data.append(inputs[i])
    else:
        data[index] = inputs[i]

print(len(data))
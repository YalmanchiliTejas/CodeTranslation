import os, sys, re, math

N = int(input())
H = [int(n) for n in input().split()]

max_array = [H[0]]
for i in range(1, len(H)):
    max_array.append(max(H[i], max_array[-1]))

count = 0
for i in range(len(H)):
    if H[i] == max_array[i]:
        count += 1

print(count)

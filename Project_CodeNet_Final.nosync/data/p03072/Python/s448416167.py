# coding: utf-8

N = raw_input()
H = list(map(int,raw_input().split()))

count = 0
h = 0
for i in range(len(H)):
    if h <= H[i]:
        count+=1
    if h < H[i]:        
        h = H[i]
print count

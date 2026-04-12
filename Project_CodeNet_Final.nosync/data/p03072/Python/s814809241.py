# coding:utf-8
n = int(input())
h = list(map(int, input().split()))
counter = 0

for i in range(n):
    #print(h[0:i+1])
    h_max = max(h[0:i+1])
    if (h[i] >= h_max) and (h[i] >= h[0]):
        #print(h[i])
        counter += 1
print(counter)
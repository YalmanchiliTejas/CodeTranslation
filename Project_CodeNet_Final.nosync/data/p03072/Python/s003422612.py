# coding: utf-8

n = int(input())
l = list(map(int, input().split()))

x = 0
for i in range(len(l)):
    if l[i] == max(l[:i+1]):
        x += 1

print(x)

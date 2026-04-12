# coding: utf-8
# Your code here!

X, Y, Z = map(int, input().split())
i = 1

while True:
    if X >= Y * i + Z * (i + 1):
        i += 1
        continue
    else:
        print (i - 1)
        exit()
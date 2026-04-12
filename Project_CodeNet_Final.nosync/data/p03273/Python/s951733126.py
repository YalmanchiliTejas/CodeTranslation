#coding: utf-8

h,w = map(int,raw_input().split())

a = []

for i in range(h): a.append(raw_input())

flags = [True] * (h+w)

for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            flags[i] = False
            flags[h+j] = False

i = 0
while True:
    if i>h-1: break
    if flags[i]:
        del a[i]
        del flags[i]
        h -= 1
        i -= 1
    i += 1

i = 0
while True:
    if i>w-1: break
    if flags[h+i]:
        w -= 1
        del flags[h+i]
        for j in range(h):
            a[j] = a[j][:i] + a[j][i+1:]
        i -= 1
    i += 1

for i in range(h):
    print a[i]


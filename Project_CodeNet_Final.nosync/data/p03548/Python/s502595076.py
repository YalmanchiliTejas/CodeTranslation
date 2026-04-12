#!/usr/bin/env python3

def read_line(*types): return [f(a) for a, f in zip(input().split(), types)]

x, y, z = read_line(int, int, int)

def f(i):
    return i * y + (i + 1) * z

i = 0
while True:
    if x < f(i + 1):
        break
    i += 1

print(i)

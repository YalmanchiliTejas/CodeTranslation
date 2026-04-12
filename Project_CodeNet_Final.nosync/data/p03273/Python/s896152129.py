#!/usr/bin/env python3
h, w = map(int, input().split())
a = [[i for i in input()] for _ in range(h)]
a = [i for i in a if "#" in i]
a = [list(i) for i in zip(*a)]
a = [i for i in a if "#" in i]
a = [list(i) for i in zip(*a)]
a = ["".join(i) for i in a]
print(*a, sep="\n")

#!/usr/bin/env python3
h, _ = map(int, input().split())
i = 0
for _ in range(h):
    a = input()
    c = a.count("#")
    if a.replace("#" * c, "").replace(".", "") != "" or a[i:i + c] != "#" * c:
        print("Impossible")
        exit()
    else:
        i += c - 1
print("Possible")

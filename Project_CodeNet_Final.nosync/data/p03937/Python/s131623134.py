#!/usr/bin/env python3
h, w = map(int, input().split())
a = [ input() for _ in range(h) ]
result = ''.join(a).count('#') == h + w - 1
print(['Impossible', 'Possible'][result])

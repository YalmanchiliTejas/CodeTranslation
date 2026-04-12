#!/usr/bin/env python3
H, W = map(int, input().split())
cnt = ''.join([input() for _ in range(H)]).count('#')
print(('Impossible', 'Possible')[cnt == H + W - 1])

# coding: utf-8

input_ = input().split()

rgb = input_[0] + input_[1] + input_[2]
rgb = int(rgb)

if rgb % 4 == 0:
    print('YES')
else:
    print('NO')

#!/user/bin/python
# coding: UTF-8

X, Y, Z = map(int, raw_input().split())

ans = (X - Z) / (Z + Y)
print ans
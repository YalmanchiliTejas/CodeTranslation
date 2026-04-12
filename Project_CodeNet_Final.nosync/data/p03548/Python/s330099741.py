#!/usr/bin/python
# -*- Coding: utf-8 -*-

x, y, z = (int(i) for i in input().split())

n = int((x-z)/(y+z))

print(n)
#!/usr/bin/env python3
#coding: utf-8


integer = input()
li = integer.split(" ")

li[0] = int(li[0])
li[1] = int(li[1])

if li[0] > li[1]:
    print("a > b")
elif li[0] < li[1]:
    print("a < b")
else:
    print("a == b")
#! /usr/bin/python
# -*- coding: utf-8 -*-

L = "qwertasdfgzxcvb"
s = raw_input()
while s != "#":
    cnt = 0
    if s[0] in L:
        cur = "L"
    else:
        cur = "R"
    for i in range(len(s)):
        if s[i] in L:
            if cur != "L":
                cnt += 1
            cur = "L"
        else:
            if cur == "L":
                cnt += 1
            cur = "R"
    print cnt
    s = raw_input()
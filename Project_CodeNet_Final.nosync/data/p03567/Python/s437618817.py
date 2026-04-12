# -*- coding: utf-8 -*-
# !/usr/bin/env python
# vim: set fileencoding=utf-8 :

"""
#
# Author:   Noname
# URL:      https://github.com/pettan0818
# License:  MIT License
# Created: 日 10/22 21:00:20 2017

# Usage
#
"""
def checker(target):
    if len(target.split("AC")) > 1:
        print("Yes")
    else:
        print("No")



if __name__ == '__main__':
    target = input()
    checker(target)

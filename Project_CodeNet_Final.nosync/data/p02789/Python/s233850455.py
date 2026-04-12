# -*- coding: utf-8 -*-

### TESTCASE
test = ""
#test = \
"""
1 1
"""
############
test = list(reversed(test.strip().splitlines()))
if test:
    def input2():
        return test.pop()
else:
    def input2():
        return input()
####### MAIN

n, m = map(int, input2().split())

if n == m:
    print("Yes")
else:
    print("No")



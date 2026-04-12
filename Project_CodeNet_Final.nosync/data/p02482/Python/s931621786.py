from __future__ import print_function
a, b = (int(x) for x in raw_input().split())
if a < b:
    print('a < b')
elif a > b:
    print('a > b')
elif a == b:
    print('a == b')
from sys import stdin
from re import sub

readline = stdin.readline

_ = readline()
s = readline().rstrip()
k = int(readline())

print(sub('[^{}]'.format(s[k-1]), '*', s))

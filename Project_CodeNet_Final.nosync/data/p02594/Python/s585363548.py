# coding: utf-8
# Your code here!
import sys
readline = sys.stdin.readline
read = sys.stdin.read

x, = [int(i) for i in read().split()]

if x >= 30:
    print("Yes")
else:
    print("No")



#Macで実行する時
import sys
import os
if sys.platform=="darwin":
	base = os.path.dirname(os.path.abspath(__file__))
	name = os.path.normpath(os.path.join(base, '../atcoder/input.txt'))
	sys.stdin = open(name)

l = list(input())
#print(l)
set_l = set(l)
if len(set_l)==1:
    print("No")
else:
    print("Yes")



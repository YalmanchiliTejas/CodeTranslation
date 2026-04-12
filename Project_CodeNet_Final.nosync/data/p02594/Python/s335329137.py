import sys
def get_array(): return list(map(int , sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()

from collections import defaultdict 
import math 

n = int(input())
if n >=30:
	print("Yes")
else:
	print("No")
from bisect import *

input()
L = [int(x) for x in input().split()]
n = int(input())

for _ in range(n):
    x = int(input())
    print( bisect_left(L,x) )

# n=int(input())
# a=[int(i) for i in input().split()]
# a=[int(input()) for i in range(n)]
import math
s=input()
a=s.count("A")
if a==0 or a==3:
    print("No")
else:
    print("Yes")

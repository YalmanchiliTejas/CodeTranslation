import sys
import math
input = sys.stdin.readline


N, M = (int(i) for i in input().split())  
#a = [int(i) for i in input().split()] 
#e = [[int(i) for i in input().split()] for i in range(n)] 

if N==M:
    print("Yes")
else:
    print("No")

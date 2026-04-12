import sys
import math
import numpy as np
def I():return int(sys.stdin.readline().replace("\n",""))
def I2():return map(int,sys.stdin.readline().replace("\n","").split())
def S():return str(sys.stdin.readline().replace("\n",""))
def L():return list(sys.stdin.readline().replace("\n",""))
def Intl():return [int(k) for k in sys.stdin.readline().replace("\n","").split()]
def Lx(k):return list(map(lambda x:int(x)*-k,sys.stdin.readline().replace("\n","").split()))

if __name__ == "__main__":
    a, b, c, x, y = I2()
    ans = float("inf")
    for i in range(2*max(x,y)+1):
        cost = c * i + a * max(0,x - i // 2) + b * max(0,y - i // 2)
        ans = min(cost,ans)
    print(ans)
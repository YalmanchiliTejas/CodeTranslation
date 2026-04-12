# Python template 
from collections import defaultdict 
import sys
import math 

def get_array(): return list(map(int , sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()


n = int(input())
a = get_array()

pre_sum = [0]

for i in range(n-1,-1,-1):
    pre_sum.append(pre_sum[-1]+a[i])

pre_sum = pre_sum[::-1]
mod = 1000000007
ans = 0
for i in range(n):
    ans = (ans+a[i]*pre_sum[i+1])%mod 

print(ans)



import math
from decimal import *
import random

n = int(input())
arr = list(map(int, input().split()))
cnt = 0
pref  = [0 for i in range(n)]
for i in range(n):
    cnt+=arr[i]
    pref[i] = cnt
ans = 0
for i in range(n):
    ans= (ans+(pref[n-1]-pref[i])*arr[i])%(int(1e9)+7)
print(ans)

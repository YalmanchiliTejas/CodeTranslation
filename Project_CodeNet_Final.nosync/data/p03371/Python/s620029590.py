# coding:utf-8

import sys
import math
import time
#import numpy as np
import collections
from collections import deque
import queue
import copy


#X = str(input()).split()
#a = [int(x) for x in input().split()]


ABCXY = str(input()).split()
A = int(ABCXY[0])
B = int(ABCXY[1])
C = int(ABCXY[2])
X = int(ABCXY[3])
Y = int(ABCXY[4])
ans1 = 0
ans2 = 0
ans3 = 0

XY = X

ans3=C*2*Y + A*(X-Y)

if(X<Y):
  XY = Y
  ans3 = C*2*X + B*(Y-X)


ans1 = A*X+B*Y
ans2 = C*2*XY

ans = min(ans1,ans2)
ans = min(ans,ans3)


print(ans)


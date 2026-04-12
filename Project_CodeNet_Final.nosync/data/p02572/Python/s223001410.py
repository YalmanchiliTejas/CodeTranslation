from collections import defaultdict
from collections import deque
from collections import Counter
import math

def readInt():
	return int(input())
def readInts():
	return list(map(int, input().split()))
def readChar():
	return input()
def readChars():
	return input().split()

n = readInt()
a = readInts()

ruiseki = [a[-1]]
for i in range(1,n):
	ruiseki.append(ruiseki[i-1]+a[i*-1-1])

ans = 0

for i in range(n-1):
	ans = (ans+(a[i]%(10**9+7)*(ruiseki[-1*i-2]%(10**9+7)))%(10**9+7))%(10**9+7)


print(ans)
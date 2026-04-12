from collections import deque
import sys, copy, itertools,heapq
input = sys.stdin.readline
 
n = int(input())
A = list(map(int,input().split()))
 
suma = sum(A)
a = (suma ** 2)
 
b =0
for i in range(n):
  b += A[i]**2
 
ans = (a-b)//2
 
answer = ans % (10**9 +7)
 
#print(a)
#print(b)
#print(ans)
print(answer)
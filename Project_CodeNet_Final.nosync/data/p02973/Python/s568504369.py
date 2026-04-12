#最長増加部分列問題 (LIS) 
import bisect

N = int(input())
seq = [0] * N
for i in range(N):
  seq[i] = int(input())

LIS = [-1] * N
LIS[-1] = seq[0]
#print(LIS)
for i in range(1, len(seq)):
    LIS[bisect.bisect_left(LIS, seq[i]) - 1] = seq[i]
    #print(LIS)
#print(LIS)
c = LIS.count(-1)
print(len(LIS) - c)
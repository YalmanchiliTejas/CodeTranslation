import sys

N = int(sys.stdin.readline().strip())
vs = [int(a) for a in sys.stdin.readline().strip().split(" ")]

M = 1000000000 + 7

ret = 0
sum = 0
for j in range(1, N):
    sum += vs[j - 1]
    ret += (vs[j] * sum) % M
    ret = ret % M
print(ret)

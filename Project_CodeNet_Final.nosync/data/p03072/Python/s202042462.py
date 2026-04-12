import sys


N = int(sys.stdin.readline())

H = list(map(int, sys.stdin.readline().split()))

max = 0
count = 0
for i in range(len(H)):
    if(max <= H[i]):
        max = H[i]
        count +=1

print(count)

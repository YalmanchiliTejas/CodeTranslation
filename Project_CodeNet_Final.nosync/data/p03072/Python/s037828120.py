import sys
input = sys.stdin.readline

N = int(input())
H = list(map(int,input().split()))
high = 0
count = 0
for i in range(N):
    if H[i] >= high:
        count += 1
        high = H[i]
print(count)

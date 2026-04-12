import sys

input = sys.stdin.readline
n = int(input())
h_list = list(map(int, input().split()))
max_h = 0
cnt = 0
for h in h_list:
    if h >= max_h:
        cnt += 1
        max_h = h
print(cnt)

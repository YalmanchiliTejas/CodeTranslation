import sys
input = sys.stdin.readline
N = int(input())
li_H = list(map(int, input().split()))
count = 1
max = li_H[0]
for i in range(1, N):
    if li_H[i] >= max:
        count += 1
        max = li_H[i]
print(count)
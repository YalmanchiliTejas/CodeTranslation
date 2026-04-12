import sys
input = sys.stdin.readline
n = int(input())
h = input().split()
count = n
for i in range(n):
    h[i] = int(h[i])
    if i > 0:
        for j in range(i):
            if h[j] > h[i]:
                count -= 1
                break
print(count)
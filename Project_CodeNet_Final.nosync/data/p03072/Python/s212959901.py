import sys
input = sys.stdin.readline

input()
h = list(map(int, input().split()))
count = 0
height_max = 0
for item in h:
    if height_max <= item:
        height_max = item
        count += 1
print(count)
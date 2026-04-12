import sys
input = sys.stdin.readline

N = int(input().rstrip())
H = map(int, input().rstrip().split())

top = 0
count = 0
for x in H:
    if top <= x:
        count += 1
        top = x

print(count)

import sys
N = int(sys.stdin.readline().rstrip())
H = list(map(int, sys.stdin.readline().rstrip().split()))
higest = 0
ans = 0
for h in H:
    if h >= higest:
        ans += 1
        higest = h
print(ans)
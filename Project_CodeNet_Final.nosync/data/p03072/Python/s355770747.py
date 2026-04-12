from sys import stdin

readline = stdin.readline
_ = readline()

cnt = 0
m = 0
for h in map(int, readline().split()):
    if h >= m:
        m = h
        cnt += 1
print(cnt)

N = int(input())
h0 = 0
cnt = 0
for h in map(int, input().split()):
    if h >= h0:
       cnt += 1
       h0 = h
print(cnt)
H, W = map(int, raw_input().split())
A = [raw_input() for _ in range(H)]
cnt = 0
for al in A:
    cnt += al.count("#")
if cnt == H + W - 1:
    print "Possible"
else:
    print "Impossible"

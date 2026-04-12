N = int(raw_input())
H = map(int, raw_input().split())

max = 0
count = 0
for i in xrange(len(H)):
    if max <= H[i]:
        max = H[i]
        count += 1

print count
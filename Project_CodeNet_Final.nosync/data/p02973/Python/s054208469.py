import bisect

N = int(input())
H = []
for _ in range(N):
    a = int(input())
    ind = bisect.bisect_right(H, -a)
    if ind == len(H):
        H.append(-a)
    else:
        H[ind] = -a
print(len(H))

N = int(input())
H = list(map(int,input().split()))

c = 0
maxh = -1
for i in range(N):
    if maxh <= H[i]:
        c += 1
        maxh = H[i]
print(c)
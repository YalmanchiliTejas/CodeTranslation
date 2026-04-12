N = int(input())
H = [int(i) for i in input().split()]
h_max = 0
c = 0
for i in range(N):
    if h_max <= H[i]:
        c += 1
        h_max = H[i]
print(c)
N = int(input())
H = [int(i) for i in input().split()]
H_max = H[0]
can = 0
for i in range(N):
    if H_max <= H[i]:
        can += 1
        H_max = H[i]
print(can)
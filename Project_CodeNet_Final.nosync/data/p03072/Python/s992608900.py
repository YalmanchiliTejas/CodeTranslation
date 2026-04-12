N = int(input())
H = list(map(int,input().split()))

maxHeight = 0
count = 0
for i in range(N):
    if H[i] >= maxHeight:
        count += 1
        maxHeight = H[i]
print(count)
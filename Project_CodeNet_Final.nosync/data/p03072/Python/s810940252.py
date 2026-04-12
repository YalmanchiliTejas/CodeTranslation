N = int(input())
H = list(map(int,input().split()))

max_height = H[0]
count = 0
for i in range(N):
    if max_height <= H[i]:
        count += 1
        max_height = H[i]
print(count)
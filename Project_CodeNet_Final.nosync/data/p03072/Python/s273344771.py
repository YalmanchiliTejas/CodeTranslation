N = int(input())
H = list(map(int,input().split()))

max_h = H[0]
counter = 0
for i in range(N):
    if max_h <= H[i]:
        max_h = H[i]
        counter += 1
print(counter)
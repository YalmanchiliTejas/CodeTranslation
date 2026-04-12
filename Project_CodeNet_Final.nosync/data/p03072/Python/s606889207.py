N = int(input())

H = [int(i) for i in input().split()]

count = 0
h = 0
for i in range(N):
    if H[i] >= h:
        count += 1
        h = H[i]
print(count)
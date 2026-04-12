N = int(input())
H = [int(i) for i in input().split()]
curr = H[0]
count = 1
for i in range(1, N):
    if curr <= H[i]:
        curr = H[i]
        count = count + 1

print(count)
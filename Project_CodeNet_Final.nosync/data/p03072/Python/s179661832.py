N = int(input())
H = [int(i) for i in input().split()]

count = 0
max_H = 0

for i in range(N):
    max_H = max(max_H,H[i])
    if H[i]>=max_H:
        count += 1

print(count)
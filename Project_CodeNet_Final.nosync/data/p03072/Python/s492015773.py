N = int(input())

H = list(input().split())
H = [int(H[i]) for i in range(N)]
count = 1

for i in range(1, N):
    if H[i] >= max(H[0:i]):
        count += 1

print(count)
N = int(input())
H = list(map(int,input().split()))
high = 0
score = 0
for j in range(N):
    if high <= H[j]:
        score += 1
        high = H[j]

print(score)
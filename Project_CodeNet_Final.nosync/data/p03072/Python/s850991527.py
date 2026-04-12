N = int(input())
H = list(map(int,input().split()))
maxHeight = 0
answer = 0
for i in range(N):
    if H[i] >= maxHeight:
        answer += 1
    maxHeight = max(maxHeight,H[i])
print(answer)
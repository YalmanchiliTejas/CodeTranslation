N = int(input())
H = list(map(int, input().split()))
answer = 0
tmpH = 0
for i in range(N):
    if tmpH <= H[i]:
        answer += 1
        tmpH = H[i]
print(answer)


N = int(input())
H = list(map(int,input().split()))

answer = 0
for i in range(len(H)):
    if max(H[0:i+1]) == H[i]:
        answer += 1

print(answer)
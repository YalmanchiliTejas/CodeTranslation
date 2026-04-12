N = int(input())
H = [int(i) for i in input().split()]
answer = 0
tall = -1
for i in range(N):
    if(tall <= H[i]):
        answer += 1
        tall = H[i]
print(answer)
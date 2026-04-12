N = int(input())
H = [int(i) for i in input().split()] 

highest = 0
ans = 0

for i in range(N):
    if highest <= H[i]:
        highest = H[i]
        ans +=1

print(ans)
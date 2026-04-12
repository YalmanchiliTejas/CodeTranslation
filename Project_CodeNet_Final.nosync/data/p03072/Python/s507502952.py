N = int(input())
H = list(map(int, input().split()))

count = 0
highest = 0

for i in range(N):
    if H[i]>=H[highest]:
        count+=1
        highest = i
print(count)
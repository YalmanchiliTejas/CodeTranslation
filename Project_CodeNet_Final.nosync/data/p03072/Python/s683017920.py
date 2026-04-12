N = int(input())
H = list(map(int,input().split()))
count = 1
highest = H[0]
for i in range(1,N):
    if H[i] >= highest:
        count += 1
        highest = H[i]
print(count)

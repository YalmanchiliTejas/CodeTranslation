N = int(input())

H = list(map(int, input().split()))

count = 1
m = H[0]
for i in range(N-1):
    if H[i+1] >= m:
        count += 1
        m = H[i+1]

        
print(count)
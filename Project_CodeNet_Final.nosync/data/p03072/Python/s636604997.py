N = int(input())
H = list(map(int, input().split()))

max_num = 0
count = 0

for i in range(N):
    if max_num <= H[i]:
        count = count + 1
        max_num = H[i]
        
        
print(count)
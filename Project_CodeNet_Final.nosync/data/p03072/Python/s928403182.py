N = int(input())
H = list(map(int,input().split()))

count = 0
Hm = 0
for i in range(N):
    if Hm <= H[i]:
        count += 1
        Hm = H[i]
        
print(count)
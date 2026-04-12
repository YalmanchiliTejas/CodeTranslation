N = int(input())
H = list(map(int, input().split()))

m = 0  # 最大
re = 0
for i in range(N):
    if m <= H[i]:
        re += 1
        m = H[i]
        
print(re)
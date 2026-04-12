N = int(input())
H = [int(i) for i in input().split()]
cnt = 1
x = H[0]
for i in range(1, N):
    if x <= H[i]:
        cnt += 1
        x = H[i]
        
print(cnt)
N = int(input())
H = [int(x) for x in input().split()]

cnt  = 1
prev = H[0]
for i in range(1, N):
    if H[i] >= prev:
        cnt +=1
        prev = H[i]
    
print(cnt)
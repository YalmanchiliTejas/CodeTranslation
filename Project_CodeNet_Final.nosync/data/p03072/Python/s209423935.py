N = int(input())
H = list(int(i) for i in input().split())  
L = []
cnt = 0
for i in range(N):
    L.append(H[i])
    if H[i] >= max(L):
        cnt += 1
print(cnt)
N = int(input())
H = [0]*N
H = input().split()
H = [int(h) for h in H]
for i in range(0, N-1):
    for j in range(i+1, N):
        if H[i] > H[j]:
            H[j] = 0
H = [h!=0 for h in H]
print(sum(H))
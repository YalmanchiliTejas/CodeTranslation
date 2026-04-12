N = int(input())
H1 = list(map(int,input().split()))
H2 = [0]*(N)
total = 0
for i in range(N):
    H2[i] = H1[i]
    if H1[i] >= max(H2):
        total += 1
print(total)

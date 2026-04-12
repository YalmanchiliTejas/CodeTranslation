N = int(input())
H = [int(x) for x in input().split()]

c = 0
for j in range(N):
    c+= 1 if all(H[i] <= H[j] for i in range(j)) else 0
print(c)



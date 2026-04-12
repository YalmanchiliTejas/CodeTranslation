N = int(input())
H = list(map(int, input().split()))
sum = 1
top = H[0]
for v in range(1, N):
        if H[v] >= top:
            sum += 1
            top = H[v] 
print(sum)
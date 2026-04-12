N = int(input())
H = list(map(int, input().split()))
result = 1
 
for i in range(1, N):
    dec = True
    for j in range(i):
        if H[i] < H[j]:
            dec = False
            break
    if dec == True:
        result += 1
print(result)
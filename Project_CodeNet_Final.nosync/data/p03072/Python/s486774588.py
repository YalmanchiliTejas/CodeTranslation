n = int(input())
H = list(map(int,input().split()))
height = H[0]
counter = 1
for i in range(1,n):
    if height <= H[i]:
        counter += 1
        height = H[i]
print(counter)
N = int(input())
H = [int(i) for i in input().split(" ")]

i = 1
maxH = H[0]
for j in range(N-1):
    if maxH <= H[j+1]:
        i += 1
        maxH = H[j+1]
print(i)
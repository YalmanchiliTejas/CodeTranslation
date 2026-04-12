N = int(input())
H = list(map(int,input().split()))

count = 0
maxH = 0

for i in H:
    if maxH <= i:
        count += 1
    maxH = max(maxH,i)

print(count)
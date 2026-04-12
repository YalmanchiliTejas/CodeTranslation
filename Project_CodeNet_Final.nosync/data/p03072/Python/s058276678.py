N = int(input())
H = []
for i in input().split():
    H.append(int(i))

max = 0
sum = 0
for i in H:
    if max <= i:
        sum += 1
        max = i
print(sum)
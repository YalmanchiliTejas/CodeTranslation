a = int(input())
H = list(map(int, input().split()))
max =H[0]
counter = 0
for i in range(a):
    if H[i] >= max:
        counter += 1
        max = H[i]

print(counter)
N = int(input())
H = input().split()
max_height = 0
count = 0

for j in range(N):
    if int(H[j]) >= max_height :
        count = count + 1
        max_height = int(H[j])

print(count)


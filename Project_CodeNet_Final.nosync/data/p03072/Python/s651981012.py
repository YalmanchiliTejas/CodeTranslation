N = int(input())
Mountain = [int(i) for i in input().split()] 

count = 0
height = 0
for i in range(N):
    if height <= Mountain[i]:
        height = Mountain[i]
        count += 1

print(count)
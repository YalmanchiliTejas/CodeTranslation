N = int(input())
num = input().split()
num = list(map(int, num))

max = num[0]
count = 1

for i in range(N-1):
    if max <= num[i+1]:
        count += 1
        max = num[i+1]

print(count)

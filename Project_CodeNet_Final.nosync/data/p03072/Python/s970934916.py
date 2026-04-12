N = int(input())
list_H = list(map(int, input().split()))

max = 0
count = 0

for i in range(N):
    if list_H[i] >= max:
        max = list_H[i]
        count += 1
    elif list_H[i] < max:
        pass

print(count)
n = int(input())
h = input().split()
num = 1

h = [int(s) for s in h]
for i in range(1, n):
    for j in range(0, i+1):
        if h[j] > h[i]:
            break
        if i == j:
            num += 1

print(num)

n = int(input())
mountains = [int(i) for i in input().split()]

res = 0

for i in range(n):
    temp = 1
    for j in range(i):
        if mountains[j] > mountains[i]:
            temp -= 1
            break
    res += temp

print(res)
n = int(input())

L = list(map(int,input().split()))

mountain = int(1)
for i in range(1, n):
    for j in range(i):
        if int(L[j]) > int(L[i]):
            break
        if int(L[j]) <= int(L[i]) and j == i-1:
            mountain += 1
            break
        if int(L[j]) <= int(L[i]):
            continue

print(mountain)

n = int(input())
k = list(input())
s = int(input())

target = k[s -1]

for i in range(len(k)):
    if k[i] != target:
        k[i] = '*'
print(''.join(k))
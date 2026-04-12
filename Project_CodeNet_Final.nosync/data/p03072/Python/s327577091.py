# ABC 124: B – Great Ocean View
N = int(input())
H = [int(s) for s in input().split()]

count = 1

for i in range(1, len(H)):
    for j in range(i):
        if H[i] < H[j]:
            break
    else:
        count += 1

print(count)
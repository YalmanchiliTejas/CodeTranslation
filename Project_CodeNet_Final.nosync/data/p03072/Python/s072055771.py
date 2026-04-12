N = int(input())
H = [int(i) for i in input().split()]

i = 0
while i < len(H) - 1:
    if H[i] > H[i + 1]:
        del H[i + 1]
    else:
        i += 1
        if i >= len(H) - 1:
            break

print(len(H))
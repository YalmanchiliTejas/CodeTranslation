N = int(input())
H = list(map(int, input().split()))

ans = 0

i = 0
j = 0
while i < len(H):
    j = i
    isOK = True
    while j >= 0:
        if H[i] < H[j]:
            isOK = False
            break
        j -= 1
    if isOK:
        ans += 1
    i += 1

print(ans)
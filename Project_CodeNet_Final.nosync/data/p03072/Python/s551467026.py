N = int(input().rstrip())
H = list(map(int, input().rstrip().split()))
a = H[0]
can = [1]
for i in range(1, N):
    if a > H[i]:
        continue
    elif a < H[i]:
        a = H[i]
        can.append(i+1)
    else:
        can.append(i+1)
print(len(can))
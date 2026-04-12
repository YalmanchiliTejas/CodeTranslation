N = int(input())
H = list(map(int, input().split()))
maxH = H[0]
S = []
for i in H:
    if i >= maxH:
        S.append(i)
        maxH = i
print(len(S))
n = int(input())

D = {}

for i in range(26):
    D[chr(i+ord('a'))] = float('inf')

for _ in range(n):
    S = list(input())

    for i in range(26):
        count = S.count(chr(i+ord('a')))
        if count < D[chr(i+ord('a'))]:
            D[chr(i+ord('a'))] = count

ans = []

for i in range(26):
    if D[chr(i+ord('a'))] < float('inf'):
        for j in range(D[chr(i+ord('a'))]):
            ans.append(chr(i+ord('a')))
ans.sort()

print(*ans,sep="")
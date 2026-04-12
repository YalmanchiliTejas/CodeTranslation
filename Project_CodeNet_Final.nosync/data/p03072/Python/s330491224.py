N = int(input())
mts = list(map(int, (input().split(' '))))

score = 0
asdf = []
for i, mt in enumerate(mts):
    asdf.append(mt)
    if max(asdf) == asdf[i]:
        score += 1
print(score)


H, W = map(int, input().split())
a = [list(map(str, input())) for i in range(H)]
counter = []

for i in range(H):
    if list(set(a[i])) != ["."]:
        counter.append(list(a[i]))

b = list(zip(*counter))
banswer = []

for i in range(W):
    if list(set(b[i])) != ["."]:
        banswer.append(list(b[i]))

answer = list(zip(*banswer))

for j in answer:
    result = "".join(j)
    print(result)

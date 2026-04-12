h,w = map(int,input().split())
L = []
for i in range(h):
    L.append(list(input()))
L = [x for x in L if "#" in x]
L = [x for x in zip(*L)]
L = [x for x in L if "#" in x]
L = [x for x in zip(*L)]
for i in range(len(L)):
    print(*L[i],sep = "")
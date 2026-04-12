from itertools import permutations

h,w = map(int,input().split())
nec = []
for i in range(h):
    s = input()
    for j in range(w):
        if s[j] == "#":
            nec.append([i,j])

if len(nec) == h+w-1:
    print("Possible")
else:
    print("Impossible")




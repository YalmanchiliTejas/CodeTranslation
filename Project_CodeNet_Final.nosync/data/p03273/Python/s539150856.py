H,W = map(int, input().split())
List = []
for i in range(H):
    List.append([a for a in input()])
i = 0
j = 0
while i < len(List):
    if List[i].count("#") == 0:
        del List[i]
        i -= 1
    i += 1

while j < len(List[0]):
    c = 0
    for k in range(len(List)):
        if List[k][j] == ".":
            c += 1
    if c == len(List):
        for k in range(len(List)):
            List[k] = List[k][:j] + List[k][j+1:]
        j -= 1
    j += 1

for l in range(len(List)):
    print("".join(List[l]))
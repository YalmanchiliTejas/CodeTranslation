def allb(S):
    for i in S:
        if not i == '.':
            return False
    return True

H,W = list(map(int,input().split()))
masu = [input() for i in range(H)]
masu = [i for i in masu if not allb(i)]
new = [[] for i in range(W)]
for i in range(len(masu)):
    for j in range(len(masu[0])):
        new[j].append(masu[i][j])
new = [i for i in new if not allb(i)]
masu = [[] for i in range(W)]
for i in range(len(new)):
    for j in range(len(new[0])):
        masu[j].append(new[i][j])
for i in masu:
    if i:
        for j in i:
            print(j,end="")
        print()

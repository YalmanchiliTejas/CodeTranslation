#実装が200点としては重い
h,w = map(int, input().split( ))

a_ = []

for i in range(h):
    ai = input()
    if ai!='.'*w:
        a_.append(ai)
#print(a_)
h = len(a_)

a = [[a_[i][j] for j in range(w)] for i in range(h)]
#print(a)
rmv = set()
for j in range(w):
    flag = True
    for i in range(h):
        if a[i][j] =="#":
            flag = False
            break
    if flag:
        rmv.add(j)
#print(rmv)
for i in range(h):
    rem = []
    for j in range(w):
        if j not in rmv:
            rem.append(a[i][j])
    print("".join(rem))


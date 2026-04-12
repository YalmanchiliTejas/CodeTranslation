na = lambda: list(map(int, input().split()))

h, w = na()
t = []
cnt = 0
for i in range(h):
    I = list(input())
    if not("#" in I):
        cnt += 1
        continue
    t.append(I)
output = []
for j in range(w):
    flag = False
    for i in range(h-cnt):
        if t[i][j] == "#":
            flag = True
    if flag:
        output.append(j)
for T in t:
    for num, i in enumerate(T):
        if num in output:
            print(i, end="")
    print()
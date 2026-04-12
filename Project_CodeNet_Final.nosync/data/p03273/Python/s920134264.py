h, w = map(int, input().split())
A = []
for i in range(h):
    a = str(input())
    if a == '.'*w:
        continue
    else:
        A.append(a)

non_use = set()
for i in range(w):
    flag = True
    for j in range(len(A)):
        if A[j][i] == '#':
            flag = False
            break
    if flag:
        non_use.add(i)

ans = []
for i in range(len(A)):
    temp = ''
    for j in range(w):
        if j in non_use:
            continue
        else:
            temp += A[i][j]
    ans.append(temp)

for s in ans:
    print(s)

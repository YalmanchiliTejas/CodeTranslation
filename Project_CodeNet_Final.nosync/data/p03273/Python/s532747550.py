h, w = map(int, input().split())
A = [[] for _ in range(h)]
for i in range(h):
    A[i] = list(input())
flag = True
while flag:
    flag = False
    for i, a in enumerate(A):
        if not '#' in a:
            flag = True
            A.pop(i)
            break
    for j in range(len(A[0])):
        a = []
        for i in range(len(A)):
            a.append(A[i][j])
        if not '#' in a:
            flag = True
            for i, a in enumerate(A):
                A[i].pop(j)
            break
for a in A:
    temp = ''.join(a)
    print(temp)
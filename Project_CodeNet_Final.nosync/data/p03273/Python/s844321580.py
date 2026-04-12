# coding:utf-8

def inpl(): return list(map(int, input().split()))

h, w = inpl()
A = []
for i in range(h):
    a = list(input())
    A.append(a)

rows = [False for _ in range(h)]
for i in range(h):
    if A[i] != ['.' for _ in range(w)]:
        rows[i] = True

B = list(map(list, zip(*A)))[:]  # map(list, zip(* A))としておかないとタプル型になってしまう
cols = [False for _ in range(w)]
for i in range(w):
    if B[i] != ['.' for _ in range(h)]:
        cols[i] = True

ans = []
for i in range(h):
    if rows[i]:
        tmp = []
        for j in range(w):
            if cols[j]:
                tmp.append(A[i][j])
        if tmp:
            ans.append(tmp)

for i in range(len(ans)):
    print(''.join(ans[i]))
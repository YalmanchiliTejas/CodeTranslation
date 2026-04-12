def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))

h,w = iim()
l = []
for i in range(h):
    s = list(input())
    if '#' in s:
        l.append(s)

h = len(l)
for j in range(w)[::-1]:
    flag = True
    for k in range(h):
        if l[k][j] == '#':
            flag = False
    if flag:
        for n in range(h):
            l[n].pop(j)

for m in range(h):
    print(''.join(l[m]))

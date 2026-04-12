h,w = map(int,input().split())
a = [input() for i in range(h)]
cnt = 0
b = []
for i in a:
  if i.count('.') != w:
    b.append(i)
  else:
    cnt += 1
if len(b) == 1:
    print(b[0].replace('.',''))
else:
    b = list(map(list,b))
    transpose = []
    c = []
    d = []
    for i in range(len(b[0])):
        tmp = []
        for v in b:
            tmp.append(v[i])
        transpose.append(tmp)
    for i in transpose:
        c.append(''.join(i))
    for i in c:
        if i.count('.') != h-cnt:
            d.append(i)
    d = list(map(list,d))
    transpose = []
    c = []
    for i in range(len(d[0])):
        tmp = []
        for v in d:
            tmp.append(v[i])
        transpose.append(tmp)
    for i in transpose:
        print(''.join(i))
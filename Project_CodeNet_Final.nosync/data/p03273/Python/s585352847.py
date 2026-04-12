h,w = map(int, input().split())
li = []
for i in range(h):
    a = list(input())
    '''
    if all([a[i] == "." for i in range(w)]):
        continue
    else:
        li.append(a)
    '''
    if "#" in a:
      li.append(a)
for j in range(w):
    #if all([li[k][j] == "." for k in range(len(li))]):
    if all(li[k][j] == "." for k in range(len(li))):
        for k in range(len(li)):
            #li[k][j] == ""
            li[k][j] = ""
for m in range(len(li)):
    print("".join(li[m]))
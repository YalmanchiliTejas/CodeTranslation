h, w = (int(i) for i in input().split(' '))
m = []

def trans(string, h ,w):
    m = []
    for i in range(0, w):
        m.append(string[i::w])

    return m, w, h

def cut_dot(string_list, h, w):
    m = []
    cnt = 0
    for i in range(h):
        if string_list[i].count('.') != w:
            m.append(string_list[i])
        else:
            cnt += 1
    if cnt:
        return m, h-cnt, w, True
    else:
        return m, h-cnt, w, False

for i in range(h):
    m.append(input())

loop = True
while loop:
    m, h ,w, loop = cut_dot(m,h,w)
    if loop:
        m, h, w = trans(''.join(m), h, w)
        
for i in m:
    print(i)

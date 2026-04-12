
h, w = map(int,input().split())
hako = list()

for i in range(h):
    ww = ["." for _ in range(w)]
    st = list(str(input()))
    if st != ww:
        hako.append(list(st))


hako2 = []
for i in range(w):
    one = []
    for onelist in hako:
        one.append(onelist[i])
    hako2.append(one)
    
hako3 = []
for _ in hako2:
    check = ["." for pp in range(len(_))]
    if _ != check:
        hako3.append(_)
        
hako4 = []

for i in range(len(hako3[0])):
    one = []
    for onelist in hako3:
        one.append(onelist[i])
    hako4.append(one)
    
for _ in hako4:
    strs = ""
    for char in _:
        strs += char
    print(strs)
    
    
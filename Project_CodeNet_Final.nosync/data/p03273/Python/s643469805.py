h,w = input().split()
h = int(h)
w = int(w)
inp = []
count = 0
for i in range(h):
    tmp_input = list(input())
    if '#' in tmp_input:
        inp.append(tmp_input)
    else:
        count += 1
inp2 = list(map(list,zip(*inp)))
youso = []
for i in range(w):
    if "#" in inp2[i]:
        pass
    else:
        youso.append(i)
youso.reverse()
if len(youso) != 0:
    for i in range(len(youso)):
        for j in range(h-count):
            del inp[j][youso[i]]
else:
    pass
for i in range(len(inp)):
    mojiretu = ''.join(inp[i])
    print(mojiretu)

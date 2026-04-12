# ABC107
# B
# Grid Compression

h, w = map(int, input().split())
a_list = []
for i in range(h):
    _tmp = input()
    if set(_tmp).issuperset({"#"}):
        a_list.append(_tmp)

a_list_T = [list(x) for x in zip(*a_list)]
tmp_list = []

for i in range(w):
    _tmp = a_list_T[i]
    if set(_tmp).issuperset({"#"}):
        tmp_list.append(_tmp)
        
ans = [list(x) for x in zip(*tmp_list)]

for _l in ans:
  print(*_l,sep="")

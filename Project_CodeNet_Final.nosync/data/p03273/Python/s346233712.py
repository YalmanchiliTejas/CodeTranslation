H,W = map(int,input().split())
li = [input() for i in range(H)]
num_lists = []
num_lists2 = []
for i in range(H):
    if "#" in li[i]:
        print("") 
    else :
        num_lists.append(i)
for i in reversed(num_lists):
    li.pop(i)
n_H = len(li)
for i in range(W) :
    ch_li = []
    for j in range(n_H):
        ch_li.append(li[j][i])
    if "#" in ch_li:
        print("")
    else :
        num_lists2.append(i)
for i in reversed(num_lists2):
    for k in range(n_H) :
        li[k] = li[k][:i]+li[k][(i+1):]
        
for i in li:
    for j in i:
        print(j,end="")
    print()
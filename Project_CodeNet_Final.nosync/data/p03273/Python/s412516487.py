h,w=map(int,input().split())
box=[list(input()) for i in range(h)]
box_y=[]
for i in range(h):
    if "#" in box[i]:box_y.append(box[i])

box_t=[[] for _ in range(len(box_y))]
for i in range(w):
    if any(["#"==box_y[j][i] for j in range(len(box_y))]):
        for j in range(len(box_y)):
            box_t[j].append(box_y[j][i])

for i in box_t:
    print("".join(i))
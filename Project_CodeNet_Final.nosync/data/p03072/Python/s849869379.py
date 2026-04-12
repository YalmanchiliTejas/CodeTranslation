N = int(input())
H_list = [int(x) for x in input().split()]
cnt = 1
for i, H in enumerate(H_list):
    if (i==0): continue
    visible = True
    for j in range(i):
        if (H_list[j] > H):
            visible = False
            break
    if (visible):
        cnt += 1
print(cnt)            

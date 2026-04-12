n = int(input())
h_list = list(map(int,input().split()))	
count = 0
view = True
for index,h in enumerate(h_list):
    target_h = h
    for i in range(index):
        if target_h >= h_list[i]:
            pass
        else:
            view = False
            break
    if view:
        count += 1
    view = True

print(count)
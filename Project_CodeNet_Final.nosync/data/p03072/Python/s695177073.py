cnt = int(input())
all_mntns = map(int,input().split(" "))
max_height = 0
view_cnt = 0


for mntn in all_mntns:
  if mntn >= max_height:
    view_cnt = view_cnt + 1
    max_height = mntn
print (view_cnt)
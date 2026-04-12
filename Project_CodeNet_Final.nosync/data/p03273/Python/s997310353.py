h,w=map(int,input().split())
g_list=[]
w_count=[0]*w

for i in range(h):
  a=input()
  if '#' in a:
    g_list.append(list(a))
    a_char=list(g_list[len(g_list)-1])
    for j in range(len(a_char)):
      if a_char[j] == '#':
        w_count[j] +=1

for k in range(len(w_count)):
  if w_count[len(w_count)-k-1] == 0:
    for l in range(len(g_list)):
      g_list[l].pop(len(w_count)-k-1)


for m in range(len(g_list)):
  print(''.join(g_list[m]))

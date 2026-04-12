a,b,c,x,y = map (int,input().split())
max_xy = max(x,y)
count_x=0
count_y=0
p=0
p_min = c*2*max_xy

for i in range(0,max_xy+1):
    #c
    x_last = x-i
    y_last = y-i
    if x_last <0 : x_last=0
    if y_last <0 : y_last=0
    p = c*2*i + a*(x_last) + b*(y_last)
    p_min = min(p_min,p)
print(p_min)
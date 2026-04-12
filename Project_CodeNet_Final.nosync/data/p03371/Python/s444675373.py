a,b,c,x,y = map(int,input().split())
c_max = max(x,y)*2
#print(i) 0,2,4,6
tmp = 0
for i in range(0,c_max+1,2):
    if i == 0:
        tmp = a*x+b*y
        continue
    mi = i//2
    all_sum = max(0,(x-mi))*a+max(0,(y-mi))*b+i*c
    if all_sum <= tmp:
        tmp = all_sum
print(tmp)
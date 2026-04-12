a,b,c,x,y = map(int,input().split())
# print(a,b,c,x,y)

#Cについての全列挙する
v1 = max(x*2,y*2)*c
v2 = a*x+b*y
v3=120000*100000
for i in range(max(x,y)+1):
    c_sum = c*2*(i)
    if x > i:
        c_sum += a*(x-i)
    if y > i:
        c_sum += b*(y-i)
    if c_sum < v3:
        v3 = c_sum
    # print(c_sum)

 # print(v1,v2,v3)
print(min(v1,v2,v3))

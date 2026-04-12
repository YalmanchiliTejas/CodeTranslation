def dfs(l,x,y):
    
    if x+1 is w and y+1 is h:
        return l
    
    #right
    if w > x+1:
        if "#" is l[y][x+1]:

            l2 = list(l)
            l2[y][x+1] = "."

            return dfs(l2,x+1,y)

    #down
    if h > y+1:
        if "#" is l[y+1][x]:
            l3 = list(l)
            l3[y+1][x]= "."
            return  dfs(l3,x,y+1)



h,w = map(int,raw_input().split())


l = []
for i in range(h):
    l.append(list(raw_input()))

# print l
l[0][0] = "."
l2 = dfs(l,0,0)
# print l2
if l2:
    if "#" in [x for sublist in l2 for x in sublist]:
        print "Impossible"
    else:
        print "Possible"
else:
    print "Impossible"
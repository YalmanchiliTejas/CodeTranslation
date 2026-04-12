pa, pb, pab, x, y = map(int, input().split())
li = []
if x-y>= 0:
    li.append(pa*x+pb*y)
    li.append(pa*(x-y)+pab*2*y)
    li.append(pab*2*x)
if y-x>= 0:
    li.append(pa*x+pb*y)
    li.append(pb*(y-x)+pab*2*x)
    li.append(pab*2*y)
li.sort()
print(li[0])
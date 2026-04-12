a,b,c,x,y = map(int, input().split())
cand = []
cand.append(a*x + b*y)
cand.append(max(x,y)*2*c)
if x > y:
    cand.append(min(x,y)*2*c + abs(x-y)*a)
else:
    cand.append(min(x,y)*2*c + abs(x-y)*b)
print(min(cand))
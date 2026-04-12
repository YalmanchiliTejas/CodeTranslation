r,g,b=map(int,input().split())
print(['NO',"YES"][(r*100+g*10+b)%4==0])
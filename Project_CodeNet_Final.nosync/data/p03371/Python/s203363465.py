a,b,c,x,y = map(int,input().split())
xy = max(x,y)*2+1
print(min([c*i + max(0,a*(x-i//2)) +max(0,b*(y-i//2)) for i in range(0,xy,2)]))
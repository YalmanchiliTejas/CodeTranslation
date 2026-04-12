a,b,c,x,y = map(int,input().split())
print(min((min(x,y)*min(a+b,2*c) + (max(x,y)-min(x,y))*(max(x,y)==y)*b + (max(x,y)-min(x,y))*(max(x,y)==x)*a), max(x,y)*2*c))
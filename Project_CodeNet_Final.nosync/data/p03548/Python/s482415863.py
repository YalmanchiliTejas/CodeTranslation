x,y,z=map(int,input().split())
mitumori=x//(y+z)
if x - mitumori*(y+z)>=z:print(mitumori)
else:print(mitumori-1)

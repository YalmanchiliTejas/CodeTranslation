r,g,b=map(int,input().split())
print('YNEOS'[(100*r+10*g+b)%4!=0::2])
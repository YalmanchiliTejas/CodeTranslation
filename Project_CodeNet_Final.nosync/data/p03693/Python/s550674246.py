r,g,b=map(int,input().split());print('YNEOS'[(r*100+g*10+b)%4!=0::2])

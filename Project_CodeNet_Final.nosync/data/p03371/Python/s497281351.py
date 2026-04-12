a,b,c,x,y=map(int,input().split())
buy_x=x
buy_y=y
buy_z=0
ans=a*buy_x+b*buy_y

for i in range(max(x,y)*2):
    if (a+b>c*2):
        if (buy_x>0 and buy_y>0):
            buy_x-=1
            buy_y-=1
            buy_z+=2
        elif (buy_x==0 and buy_y>0 and b>c*2):
            buy_y-=1
            buy_z+=2
        elif (buy_x>0 and buy_y==0 and a>c*2):
            buy_x-=1
            buy_z+=2
    else:
        break
        
print(buy_x*a+buy_y*b+buy_z*c)


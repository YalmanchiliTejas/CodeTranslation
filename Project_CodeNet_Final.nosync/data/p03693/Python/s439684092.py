num = input().split() 
temp = ''
for i in range(len(num)):
    temp = temp + num[i]
print( ['NO','YES'][int(temp)%4==0] )
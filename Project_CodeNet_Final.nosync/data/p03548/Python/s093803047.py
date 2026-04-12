x,y,z = map(int,input().split())
num = x//(y+z)
mod = x%(y+z)
if 0<=mod<z:num-=1
print(num)
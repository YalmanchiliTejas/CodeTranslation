x,y,z=map(int, input().split())

for i in reversed(range(0,10**5+1)):
    if x>=(y*i+(i+1)*z):
        print(i)
        break
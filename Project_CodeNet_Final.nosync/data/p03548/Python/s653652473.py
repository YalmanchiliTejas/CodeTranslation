x,y,z = map(int,input().split())
sum = y + z*2
cnt = 1
while True:
    sum += y+z
    if x>=sum:
        cnt+=1
    else:
        break
print(cnt)

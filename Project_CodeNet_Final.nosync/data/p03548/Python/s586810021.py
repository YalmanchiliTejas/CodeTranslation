x,y,z=map(int,input().split())

x = x - z
sum = 0
cnt = 0
while sum <= x:
    sum += y + z
    cnt += 1
print(cnt - 1)

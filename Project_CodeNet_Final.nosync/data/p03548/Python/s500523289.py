x,y,z= map(int,input().split())
res = z
cnt = 0
while res<=x:
    res += y+z
    cnt += 1
print(cnt-1)
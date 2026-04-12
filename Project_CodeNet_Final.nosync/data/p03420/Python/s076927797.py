n,k = map(int, input().split())

if k==0:
    print(n*n)
    exit()

ans=0
for b in range(k+1,n+1):
    num = n//b
    add=num * (b-k)

    nokori = n-b*num
    if nokori-k+1 > 0:
       add+= nokori - k+1

#    print("  ",b,num,add)
    ans+=add
print(ans)
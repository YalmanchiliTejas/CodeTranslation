n=int(input())
heights=list(map(int,input().split()))
#print(heights)

cnt=0
maxH=0

for height in heights:
    if maxH<=height:
        maxH=height
        cnt+=1

print(cnt)

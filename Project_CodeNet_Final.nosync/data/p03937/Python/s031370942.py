h,w = map(int, input().split())
cnt=0
for i in range(h):
    a = list(input())
    for tmp in a:
        if tmp=="#":
            cnt+=1
if cnt==h+w-1:
    print("Possible")
else:
    print("Impossible")
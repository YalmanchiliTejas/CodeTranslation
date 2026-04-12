n,x,m = map(int,input().split())
ans = x
b = x
box = [x]
c= 0
for i in range(1,n):
    b= (b**2)%m
    if b == 0:
        print(ans)
        exit() 
    if b in box:
        c = box.index(b)
        break
    ans += b
    box.append(b)
# print(c)
# print(sum(box)*(n//len(box)) + sum(box[0:n%len(box)]))


print(sum(box[:c])+sum(box[c:])*((n-c)//len(box[c:])) + sum(box[c:c+(n-c)%len(box[c:])]))

N=int(input())
l=[]

for i in range(N):
    l.append(int(input()))

l=sorted(l)
i=0
sum=0
nr=0
nl=0
right=l.pop(0)
left=right

while len(l)>1:
    if i%4==0:
        nr=l.pop(-1)
        sum+=nr-right
        right=nr        
    elif i%4==1:
        nl=l.pop(-1)
        sum+=nl-left
        left=nl
    elif i%4==2:
        nr=l.pop(0)
        sum-=nr-right
        right=nr       
    elif i%4==3:
        nl=l.pop(0)
        sum-=nl-left
        left=nl
        
    i+=1

#終わりのはじっこの処理がヤバイ? ちゃんと差がおおきくなるように配置できてるか
#11678で25出せればおけ
        
print(sum+max(abs(right-l[0]),abs(left-l[0])))
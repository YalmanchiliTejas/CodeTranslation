n,x,m = map(int,input().split())

y=x
A=[]
A.append(y)
cnt=1
su=x

for i in range(m):
    y=(y**2)%m
    cnt+=1
    if y in A:
        break
    else:
        A.append(y)
        su+=y

c=A.index(y) #周期のはじめ
d=cnt-(c+1)  #周期のはじめから次の周期のはじめで個数を求める

e=sum(A[:c]) 
#周期に入るまえまでを足しておく


f=sum(A[c:c+(n-c)%d])
    #周期からはみでた最後の部分

g=su-e#1周期分
h=g*((n-c)//d)#かけざん

print(e+h+f)
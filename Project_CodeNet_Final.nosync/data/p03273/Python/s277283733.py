h,w=map(int,input().split())
data=[]
count_x=[0]*w
count_y=[0]*h
for i in range(h):
    a_i=input()
    for j in range(w):
        if a_i[j]=="#":
            count_y[i]+=1
            count_x[j]+=1
    data.append(a_i)
for i in range(h):
    if count_y[i]!=0:
        data_i=data[i]
        ans=""
        for j in range(w):
            if count_x[j]!=0:
                ans+=data_i[j]
        print(ans)
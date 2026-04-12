#B問題
N=int(input())
H=list(map(int,input().split()))
count=0
hot=[]
for i in range(N):
    if i == 0:
        count+=1
        hot.append(H[0])
    else:
        if max(hot) <= H[i]:
            count+=1
        hot.append(H[i])
print(count)
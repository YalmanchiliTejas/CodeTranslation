
#B
N=int(input())
H =[int(j) for j in input().split()]
cnt=0
for i in range(len(H)):
    if max(H[0:i+1]) <= H[i]:
        cnt+=1
print(cnt)
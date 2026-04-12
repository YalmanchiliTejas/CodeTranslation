N=int(input())
list1=list(map(int,input().split()))
cnt=0
for i in range(N):
    if max(list1[:i+1])==list1[i]:
        cnt+=1
print(cnt)
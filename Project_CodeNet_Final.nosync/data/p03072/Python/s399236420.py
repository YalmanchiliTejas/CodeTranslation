n=int(input())
l=list(map(int,input().split()))
Max=0
cnt=0
for i in l:
    if i>=Max:
        cnt+=1
        Max=i
print(cnt)
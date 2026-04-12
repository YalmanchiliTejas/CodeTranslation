input()
n=list(map(int,input().split()))
h=0
cnt=0
for i in n:
    if h <= i:
        cnt+=1
        h=i
print(cnt)
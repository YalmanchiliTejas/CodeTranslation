n=int(input())
h=list(map(int,input().split()))
cnt=0
for x,i in enumerate(h):
    if i == max(h[:x+1]):
        cnt+=1
print(cnt)
    